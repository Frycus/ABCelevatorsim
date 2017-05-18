#include "RNG.h"
#include "Kernels.h"
#include "Generator.h"

RNG::RNG()
{
	tzs = nullptr;
	tpw = nullptr;
	tpg = nullptr;
	tpa = nullptr;
}

RNG::~RNG()
{
	delete tpw;
	delete tzs;
	delete tpg;
	delete tpa;
}

void RNG::Initialize(Kernels *kernels, int set_idx, double lambda)
{
	tpw = new UniformGenerator(kernels->GetKernel(Kernels::TPW, set_idx));
	tzs = new UniformGenerator(kernels->GetKernel(Kernels::TZS, set_idx));
	tpa = new UniformGenerator(kernels->GetKernel(Kernels::TZS, set_idx));
	tpg = new ExpGenerator(lambda, new UniformGenerator(kernels->GetKernel(Kernels::TPG, set_idx)));
}