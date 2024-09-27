//#include "LinAlg.h"
//#include <iostream>
//#include <array>
//#include <vector>
//
//class Boid
//{
//private:
//	const float f_separation = 1;
//	const float f_alignment = 1;
//	const float f_cohesion = 1;
//	const float m_range = 10;
//	const float m_velocity = 2;
//
//	std::array<float, 3> m_position {};
//	std::array<float, 3> m_heading {};
//
//public:
//	std::array<float, 3> getHeading() const { return m_heading; }
//
//	void update(std::vector<Boid> boids) {
//		// Prepare our accumulators
//		std::vector<float> avg_heading(3);
//		std::vector<float> avg_position(3);
//		int neighborhood_count = 0;
//
//		for (const auto& boid : boids)
//		{
//			const float dis = distance(m_position, boid.getHeading());
//		}
//	}
//};
