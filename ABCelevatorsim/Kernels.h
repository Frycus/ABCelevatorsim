#ifndef ABCELEVATORSIM_GENERATOR_KERNELS_H_
#define ABCELEVATORSIM_GENERATOR_KERNELS_H_

#include <map>
#include <vector>

class Kernels
{
public:
	enum GTypes
	{
		TPG = 0,	 // New passenger arrives event
		TZS,		 // Time to finish service
		TPW,		 // Time of coming in and out of elevator
		TPA,		 // Desired floor
		COUNT
	};

	Kernels();

	virtual ~Kernels();

	int GetKernel(GTypes gtype, int set) const;

	void GenerateKernels(std::string filePath);

	void ReadKernels(const std::string input_file_path);

private:

	const int kNrofSets;
	const int kSetLength;

	bool kernels_loaded_;

	std::map<GTypes, std::vector<int> > kernelSet_;
};

#endif /*AS_RANDOM_GENERATOR_KERNELS_H_*/
