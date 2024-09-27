#include <iostream>
#include <vector>
#include <chrono>
#include <random>

#include <glm.hpp>

const float f_separation = 1;
const float f_alignment = 1;
const float f_cohesion = 1;
const float range = 5;
const float velocity = 2;

struct Boid {
	glm::vec3 position{};
	glm::vec3 heading{};
};

std::vector<Boid> update(const std::vector<Boid>& boids)
{
	const std::size_t length{ boids.size() };
	std::vector<Boid> new_boids(length);

	for (std::size_t i{ 0 }; i < length; ++i)
	{
		glm::vec3 new_heading(0);
		glm::vec3 avg_heading(0);
		glm::vec3 avg_position(0);
		float neighbors = 0;

		for (std::size_t j{ 0 }; j < length; ++j) {
			if (j == i) { continue; }

			float dis = glm::distance(boids[i].position, boids[j].position);

			if (dis < range) {
				++neighbors;

				//Influence from separation: normalized direction scaled by distance and force
				new_heading += glm::normalize(boids[i].position - boids[j].position) * f_separation / dis;

				avg_heading += boids[j].heading - avg_heading / neighbors;

				avg_position += boids[j].position - avg_position / neighbors;
			}
		}

		new_heading += avg_heading * f_alignment;
		new_heading += (avg_position - boids[i].position) * f_cohesion;
		new_heading = glm::normalize(new_heading);

		new_boids[i] = Boid{ boids[i].position + new_heading * velocity, new_heading };
	}
	return new_boids;
}

int main()
{
	//std::mt19937 mt{ std::random_device{}() };
	std::mt19937 mt{ 1 };
	std::uniform_int_distribution<> dist_pos{0, 20};
	std::uniform_int_distribution<> dist_head{ -1, 1 };

	const int num = 1 << 11;

	std::cout << "Running Boids simulation (single-threaded) with " << num << " Boids." << std::endl;

	std::vector<Boid> boids(num);

	for (auto& boid : boids)
	{
		boid.position = glm::vec3({ dist_pos(mt), dist_pos(mt), dist_pos(mt) });
		boid.heading = glm::normalize(glm::vec3(1));
	}

	for (std::size_t i{ 0 }; i < 1; ++i)
	{
		auto start = std::chrono::high_resolution_clock::now();

		boids = update(boids);
		//std::cout << "Position: " << boids[0].position.x << ", " << boids[0].position.y << ", " << boids[0].position.z << std::endl;
		//std::cout << "Heading: " << boids[0].heading.x << ", " << boids[0].heading.y << ", " << boids[0].heading.z << std::endl;

		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		std::cout << "Performance: " << duration.count() << "ms" << std::endl;
	}

	//std::cout << "Heading: " << boids[0].heading.x << ", " << boids[0].heading.y << ", " << boids[0].heading.z << std::endl;
	//std::cout << "Position: " << boids[0].position.x << ", " << boids[0].position.y << ", " << boids[0].position.z << std::endl;

	return 0;
}
