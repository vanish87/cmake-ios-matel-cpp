

#include <render.hpp>
#include <Metal.hpp>
#include <iostream>

void RenderFunction()
{
	auto device = MTL::CreateSystemDefaultDevice();
	if(device->supportsFeatureSet(MTL::FeatureSet::FeatureSet_macOS_GPUFamily2_v1))
	{
		std::cout<<"GPU device create "<<"iOS_GPUFamily4_v1"<<std::endl;
	}
	else if(device->supportsFeatureSet(MTL::FeatureSet::FeatureSet_iOS_GPUFamily4_v1))
	{
		std::cout<<"GPU device create "<<"FeatureSet_iOS_GPUFamily4_v1"<<std::endl;
	}
    std::cout<<device->name()->cString(NS::UTF8StringEncoding)<<std::endl;
	// delete device;
}
