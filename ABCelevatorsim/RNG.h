#ifndef ABCELEVATORSIM_GENERATOR_RNG_H
#define ABCELEVATORSIM_GENERATOR_RNG_H
class UniformGenerator;
class ExpGenerator;
class Kernels;

struct RNG
{
	RNG();
	virtual ~RNG();

	void Initialize(Kernels *kernels, int set_idx, double lambda);

	UniformGenerator *tzs;
	UniformGenerator *tpw;
	UniformGenerator *tpa;
	ExpGenerator *tpg;
};
#endif
