

#include <render.hpp>
#include <Metal.hpp>
#include <iostream>

void RenderFunction()
{
	auto device = MTL::CreateSystemDefaultDevice();
	if(device->supportsFeatureSet(MTL::FeatureSet::FeatureSet_macOS_GPUFamily2_v1))
	{
		std::cout<<"GPU device create"<<std::endl;
	}
    //printf("%s", );
    std::cout<<device->name()->cString(NS::UTF8StringEncoding)<<std::endl;

	// delete device;
}
