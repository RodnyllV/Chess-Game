inline int clamp(int val, int min, int max) {
	if (val < min) {
		return min;
	}

	if (val > max) {
		return max;
	}

	return val;
}