#pragma once
#include <array>
#include <cmath>

template <std::size_t N>
float distance(const std::array<float, N>& pos1, const std::array<float, N>& pos2)
{
	static_assert(N == 3);

	//float xdif = pos1[0] - pos2[0];
	//float ydif = pos1[1] - pos2[1];
	//float zdif = pos1[2] - pos2[2];
	//return std::sqrtf(xdif * xdif + ydif * ydif + zdif * zdif);
	
	//std::array<float, 3> diffs{ pos1[0] - pos2[0], pos1[1] - pos2[1], pos1[2] - pos2[2] };
	//return std::sqrtf(diffs[0] * diffs[0] + diffs[1] * diffs[1] + diffs[2] * diffs[2]);
	
	std::array<float, 3> diffs{ pos1[0] - pos2[0], pos1[1] - pos2[1], pos1[2] - pos2[2] };
	return std::sqrtf(std::powf(diffs[0], 2) + std::powf(diffs[1], 2) + std::powf(diffs[2], 2));
	
}

template <std::size_t N>
void lin_diff(const std::array<float, N>& vec1, const std::array<float, N>& vec2, const std::array<float, N>& out)
{
	static_assert(N == 3);


}

template <std::size_t N>
void normalize(const std::array<float, N>& vec, const std::array<float, N>& out)
{
	static_assert(N == 3);
}
