/*****************************************************************************\
*
*  Module Name    common.cpp
*  Project        Radeon ProRender SDK rendering tutorial
*
*  Description    Radeon ProRender SDK tutorials
*
*  Copyright(C) 2011-2021 Advanced Micro Devices, Inc. All rights reserved.
*
\*****************************************************************************/

#include "common.h"

#include "Math/mathutils.h"


vertex cube_data[] = 
{
	{ -1.0f, 1.0f, -1.0f,    0.f, 1.f, 0.f,    0.f, 0.f },
	{  1.0f, 1.0f, -1.0f,    0.f, 1.f, 0.f,    1.f, 0.f },
	{  1.0f, 1.0f, 1.0f,     0.f, 1.f, 0.f,    1.f, 1.f },
	{  -1.0f, 1.0f, 1.0f,    0.f, 1.f, 0.f,    0.f, 1.f},

	{  -1.0f, -1.0f, -1.0f,  0.f, -1.f, 0.f,     0.f, 0.f },
	{  1.0f, -1.0f, -1.0f,   0.f, -1.f, 0.f,     1.f, 0.f },
	{  1.0f, -1.0f, 1.0f,    0.f, -1.f, 0.f,     1.f, 1.f },
	{  -1.0f, -1.0f, 1.0f,   0.f, -1.f, 0.f,     0.f, 1.f },

	{  -1.0f, -1.0f, 1.0f,   -1.f, 0.f, 0.f,     0.f, 0.f },
	{  -1.0f, -1.0f, -1.0f,  -1.f, 0.f, 0.f,     1.f, 0.f },
	{  -1.0f, 1.0f, -1.0f,   -1.f, 0.f, 0.f,     1.f, 1.f },
	{  -1.0f, 1.0f, 1.0f,    -1.f, 0.f, 0.f,     0.f, 1.f },

	{  1.0f, -1.0f, 1.0f,     1.f, 0.f, 0.f,    0.f, 0.f },
	{  1.0f, -1.0f, -1.0f,    1.f, 0.f, 0.f,    1.f, 0.f },
	{  1.0f, 1.0f, -1.0f,     1.f, 0.f, 0.f,    1.f, 1.f },
	{  1.0f, 1.0f, 1.0f,      1.f, 0.f, 0.f,    0.f, 1.f },

	{  -1.0f, -1.0f, -1.0f,    0.f, 0.f, -1.f ,    0.f, 0.f },
	{  1.0f, -1.0f, -1.0f,     0.f, 0.f, -1.f ,    1.f, 0.f },
	{  1.0f, 1.0f, -1.0f,      0.f, 0.f, -1.f,     1.f, 1.f },
	{  -1.0f, 1.0f, -1.0f,     0.f, 0.f, -1.f,     0.f, 1.f },

	{  -1.0f, -1.0f, 1.0f,   0.f, 0.f, 1.f,     0.f, 0.f },
	{  1.0f, -1.0f, 1.0f,    0.f, 0.f, 1.f,     1.f, 0.f },
	{  1.0f, 1.0f, 1.0f,     0.f, 0.f, 1.f,     1.f, 1.f },
	{  -1.0f, 1.0f, 1.0f,    0.f, 0.f, 1.f,     0.f, 1.f },
};



vertex plane_data[] = 
{
	{-15.f, 0.f, -15.f,    0.f, 1.f, 0.f,    0.f, 1.f},
	{-15.f, 0.f,  15.f,    0.f, 1.f, 0.f,    0.f, 0.f},
	{ 15.f, 0.f,  15.f,    0.f, 1.f, 0.f,    1.f, 0.f},
	{ 15.f, 0.f, -15.f,    0.f, 1.f, 0.f,    1.f, 1.f},
};


rpr_int indices[] = 
{
	3,1,0,
	2,1,3,

	6,4,5,
	7,4,6,

	11,9,8,
	10,9,11,

	14,12,13,
	15,12,14,

	19,17,16,
	18,17,19,

	22,20,21,
	23,20,22
};


rpr_int num_face_vertices[] = 
{
	3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3
};



void ErrorManager(int errorCode, const char* fileName, int line, rpr_context ctx)
{
	std::cout<<"ERROR detected - program will stop."<<std::endl;
	std::cout<<"file = "<< fileName << std::endl;
	std::cout<<"line = "<< line << std::endl;
	std::cout<<"error code = "<< errorCode << std::endl;
	assert(0);
}


// this is an example a good practice to check RPR memory leak
void CheckNoLeak(rpr_context context)
{
	rpr_int status = RPR_SUCCESS;

	std::vector<rpr_context_info> type;
	type.push_back(RPR_CONTEXT_LIST_CREATED_CAMERAS);
	type.push_back(RPR_CONTEXT_LIST_CREATED_MATERIALNODES);
	type.push_back(RPR_CONTEXT_LIST_CREATED_LIGHTS);
	type.push_back(RPR_CONTEXT_LIST_CREATED_SHAPES);
	type.push_back(RPR_CONTEXT_LIST_CREATED_POSTEFFECTS);
	type.push_back(RPR_CONTEXT_LIST_CREATED_HETEROVOLUMES);
	type.push_back(RPR_CONTEXT_LIST_CREATED_GRIDS);
	type.push_back(RPR_CONTEXT_LIST_CREATED_BUFFERS);
	type.push_back(RPR_CONTEXT_LIST_CREATED_IMAGES);
	type.push_back(RPR_CONTEXT_LIST_CREATED_FRAMEBUFFERS);
	type.push_back(RPR_CONTEXT_LIST_CREATED_SCENES);
	type.push_back(RPR_CONTEXT_LIST_CREATED_CURVES);
	type.push_back(RPR_CONTEXT_LIST_CREATED_MATERIALSYSTEM);
	type.push_back(RPR_CONTEXT_LIST_CREATED_COMPOSITE);
	type.push_back(RPR_CONTEXT_LIST_CREATED_LUT);

	std::vector<void*> listRemainingObjects;

	for(int iType=0; iType<type.size(); iType++)
	{

		size_t sizeParam = 0;
		status = rprContextGetInfo(context,type[iType],0,0,&sizeParam);CHECK(status);
		
		unsigned int nbObject = sizeParam / sizeof(void*);

		if ( nbObject > 0 )
		{
			std::cout<<"leak of "<< nbObject ;
				 if ( type[iType] == RPR_CONTEXT_LIST_CREATED_CAMERAS ) std::cout<<" cameras\n";
			else if ( type[iType] == RPR_CONTEXT_LIST_CREATED_MATERIALNODES ) std::cout<<" material nodes\n";
			else if ( type[iType] == RPR_CONTEXT_LIST_CREATED_LIGHTS ) std::cout<<" lights\n";
			else if ( type[iType] == RPR_CONTEXT_LIST_CREATED_SHAPES ) std::cout<<" shapes\n";
			else if ( type[iType] == RPR_CONTEXT_LIST_CREATED_POSTEFFECTS ) std::cout<<" postEffects\n";
			else if ( type[iType] == RPR_CONTEXT_LIST_CREATED_HETEROVOLUMES ) std::cout<<" heteroVolumes\n";
			else if ( type[iType] == RPR_CONTEXT_LIST_CREATED_GRIDS ) std::cout<<" grids\n";
			else if ( type[iType] == RPR_CONTEXT_LIST_CREATED_BUFFERS ) std::cout<<" buffers\n";
			else if ( type[iType] == RPR_CONTEXT_LIST_CREATED_IMAGES ) std::cout<<" images\n";
			else if ( type[iType] == RPR_CONTEXT_LIST_CREATED_FRAMEBUFFERS ) std::cout<<" framebuffers\n";
			else if ( type[iType] == RPR_CONTEXT_LIST_CREATED_SCENES ) std::cout<<" scenes\n";
			else if ( type[iType] == RPR_CONTEXT_LIST_CREATED_CURVES ) std::cout<<" curves\n";
			else if ( type[iType] == RPR_CONTEXT_LIST_CREATED_MATERIALSYSTEM ) std::cout<<" materialsystems\n";
			else if ( type[iType] == RPR_CONTEXT_LIST_CREATED_COMPOSITE ) std::cout<<" composites\n";
			else if ( type[iType] == RPR_CONTEXT_LIST_CREATED_LUT ) std::cout<<" luts\n";
			else 
			{
				std::cout<<" ???\n"; 
			}

			unsigned int idFirstTime = listRemainingObjects.size();
			listRemainingObjects.assign( idFirstTime + nbObject, nullptr );
			status = rprContextGetInfo(context,type[iType],sizeParam,&listRemainingObjects[idFirstTime],nullptr);CHECK(status);
		}
	}

	if ( listRemainingObjects.size() != 0 )
	{
		std::cout<<"Warning : this context has some leak ("<< listRemainingObjects.size() <<" item(s))\n";
	}

}


// description in header.
rpr_shape ImportOBJ(const std::string& file, rpr_scene scene, rpr_context ctx)
{
	rpr_int status = RPR_SUCCESS;

	std::ifstream infile(file.c_str());

	if ( !infile.is_open() || infile.fail() )
		return nullptr;

	std::string line;
	std::vector<rpr_float> pos;
	std::vector<rpr_float> normal;
	std::vector<rpr_float> texture;
	std::vector<rpr_int> face_pos;
	std::vector<rpr_int> face_normal;
	std::vector<rpr_int> face_texture;
	std::vector<rpr_int> face;

	while (std::getline(infile, line))
	{
		// empty line
		if ( line.size() < 2 )
			continue;

		// comment
		if ( line[0] == '#' )
			continue;

		if ( line.substr(0,2) == "v " )
		{
			std::istringstream iss(line.substr(1));
			rpr_float x, y, z;
			if (!(iss >> x >> y >> z)) { break; } // error
			pos.push_back(x);
			pos.push_back(y);
			pos.push_back(z);
		}

		if ( line.substr(0,3) == "vn " )
		{
			std::istringstream iss(line.substr(2));
			rpr_float x, y, z;
			if (!(iss >> x >> y >> z)) { break; } // error
			normal.push_back(x);
			normal.push_back(y);
			normal.push_back(z);
		}

		if ( line.substr(0,3) == "vt " )
		{
			std::istringstream iss(line.substr(2));
			rpr_float x, y, z;
			if (!(iss >> x >> y >> z)) { break; } // error
			texture.push_back(x);
			texture.push_back(y);
		}

		if ( line.substr(0,2) == "f " )
		{
			rpr_int f01,f02,f03  ,f11,f12,f13  ,f21,f22,f23 = 0;
			std::istringstream iss(line.substr(1));
			int nb = sscanf(line.c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d" , &f01, &f02, &f03, &f11, &f12, &f13, &f21, &f22, &f23);

			if ( nb != 9 )
				break; // error

			face_pos.push_back(f01-1);
			face_pos.push_back(f11-1);
			face_pos.push_back(f21-1);

			face_normal.push_back(f03-1);
			face_normal.push_back(f13-1);
			face_normal.push_back(f23-1);

			face_texture.push_back(f02-1);
			face_texture.push_back(f12-1);
			face_texture.push_back(f22-1);

			face.push_back(3);
		}
	}	

	rpr_shape meshA = 0;
    status = rprContextCreateMesh(ctx,
		(rpr_float const*)&pos[0], pos.size()/3 , 3*sizeof(float),
        (rpr_float const*)&normal[0], normal.size()/3 , 3*sizeof(float),
        (rpr_float const*)&texture[0], texture.size()/2 , 2*sizeof(float),
        (rpr_int const*)&face_pos[0], sizeof(rpr_int),
        (rpr_int const*)&face_normal[0], sizeof(rpr_int),
        (rpr_int const*)&face_texture[0], sizeof(rpr_int),
        (rpr_int const*)&face[0], face.size(), &meshA);

	if ( scene ) { status = rprSceneAttachShape(scene, meshA); }

	return meshA;
}


MatballScene::MatballScene()
{
	m_context = NULL;

	m_scene = NULL; 
	m_matsys = NULL;
	m_camera = NULL;
	m_shape_floor = NULL; 
	m_floorMaterial = NULL;
	m_floorImage = NULL;
	m_IBLimage = NULL;
	m_light = NULL;
	m_floorImageMaterial = NULL;
	m_frame_buffer = NULL;
	m_frame_buffer_res = NULL;

	return;
}

void MatballScene::Render(const std::string& outImgFileName, int iterationCount)
{
	CHECK( rprFrameBufferClear(m_frame_buffer) );

	if ( !m_usingHybridContext ) // there is no iteration for Hyrbid
	{
		CHECK( rprContextSetParameterByKey1u(m_context, RPR_CONTEXT_ITERATIONS, iterationCount) );
	}

	std::cout<<"Rendering "<<outImgFileName<<" ..."<<std::endl;
	CHECK( rprContextRender(m_context) );
	
	if ( !m_usingHybridContext ) // There is no framebuffer resolve for Hyrbid
	{
		// last argument is FALSE because we don't want a simple normalization: we also want to apply the display gamma (changed with RPR_CONTEXT_DISPLAY_GAMMA)
		CHECK( rprContextResolveFrameBuffer(m_context, m_frame_buffer, m_frame_buffer_res, false) );

		CHECK( rprFrameBufferSaveToFile(m_frame_buffer_res, outImgFileName.c_str() ) );
	}
	else
	{
		CHECK( rprFrameBufferSaveToFile(m_frame_buffer, outImgFileName.c_str() ) );
	}

	return;
}

void MatballScene::Clean()
{
	if ( m_scene ) { rprObjectDelete(m_scene); m_scene=nullptr;  }
	if ( m_matsys ) { rprObjectDelete(m_matsys); m_matsys=nullptr;  }
	if ( m_camera ) { rprObjectDelete(m_camera); m_camera=nullptr;  }
	if ( m_frame_buffer ) { rprObjectDelete(m_frame_buffer); m_frame_buffer=nullptr;  }
	if ( m_frame_buffer_res ) { rprObjectDelete(m_frame_buffer_res); m_frame_buffer_res=nullptr;  }
	if ( m_light ) { rprObjectDelete(m_light); m_light=nullptr;  }

	for(auto& i : m_matballs)
	{
		if ( i.base ) { rprObjectDelete(i.base); i.base=nullptr;  }
		if ( i.inner ) { rprObjectDelete(i.inner); i.inner=nullptr;  }
		if ( i.outer ) { rprObjectDelete(i.outer); i.outer=nullptr;  }
	}
	m_matballs.clear();

	if ( m_shape_floor ) { rprObjectDelete(m_shape_floor); m_shape_floor=nullptr;  }
	if ( m_floorMaterial ) { rprObjectDelete(m_floorMaterial); m_floorMaterial=nullptr;  }
	if ( m_floorImage ) { rprObjectDelete(m_floorImage); m_floorImage=nullptr;  }
	if ( m_IBLimage ) { rprObjectDelete(m_IBLimage); m_IBLimage=nullptr;  }
	if ( m_floorImageMaterial ) { rprObjectDelete(m_floorImageMaterial); m_floorImageMaterial=nullptr;  }

	return;
}


MatballScene::MATBALL MatballScene::Init(rpr_context context, int shapeShiftX, int shapeShiftY, bool usingHybridContext)
{

	m_usingHybridContext = usingHybridContext;
	m_context = context;

	//create scene
	CHECK( rprContextCreateScene(m_context,&m_scene) );
	CHECK( rprContextSetScene(m_context, m_scene) );


	CHECK( rprContextCreateMaterialSystem(m_context, 0, &m_matsys) );




	//Camera creation
	CHECK( rprContextCreateCamera(m_context,&m_camera) );
	CHECK( rprSceneSetCamera(m_scene,m_camera) );
	CHECK( rprObjectSetName(m_camera,(rpr_char*)"Camera001") );
	CHECK( rprCameraSetMode(m_camera,RPR_CAMERA_MODE_PERSPECTIVE) );
	CameraLook1Shape(0, 0);


	MatballScene::MATBALL newShape = AddMatball(shapeShiftX, shapeShiftY, false);

	m_shape_floor = ImportOBJ("../../Resources/Meshes/matball_floor.obj",m_scene,m_context);


	CHECK( rprContextCreateImageFromFile(m_context,"../../Resources/Textures/envLightImage.exr",&m_IBLimage) );
	CHECK( rprObjectSetName (m_IBLimage,"IBLimage") );


	//EnvironmentLight creation
	CHECK( rprContextCreateEnvironmentLight(m_context,&m_light) );
	CHECK( rprObjectSetName (m_light,"light") );
	CHECK( rprEnvironmentLightSetImage(m_light,m_IBLimage) );
	rpr_float float_P16_4[] = { -1.000000f,-0.000000f,-0.000000f,0.000000f,0.000000f,-0.000000f,1.000000f,0.000000f,-0.000000f,1.000000f,0.000000f,0.000000f,0.000000f,0.000000f,0.000000f,1.000000f };
	CHECK( rprLightSetTransform(m_light,false,(rpr_float*)&float_P16_4) );
	CHECK( rprSceneSetEnvironmentLight(m_scene,m_light) );
	

	CHECK( rprContextCreateImageFromFile(m_context,"../../Resources/Textures/amd.png",&m_floorImage) );
	CHECK( rprObjectSetName (m_floorImage,"floorImage") );

	CHECK( rprMaterialSystemCreateNode(m_matsys,RPR_MATERIAL_NODE_IMAGE_TEXTURE,&m_floorImageMaterial) );
	CHECK( rprMaterialNodeSetInputImageDataByKey(m_floorImageMaterial,RPR_MATERIAL_INPUT_DATA,m_floorImage) );
	
	if ( !usingHybridContext )
	{
		CHECK( rprMaterialSystemCreateNode(m_matsys,RPR_MATERIAL_NODE_DIFFUSE,&m_floorMaterial) );
		CHECK( rprMaterialNodeSetInputNByKey(m_floorMaterial, RPR_MATERIAL_INPUT_COLOR, m_floorImageMaterial) );
	}
	else // Hybrid only manages UBER material meaning we can't use the RPR_MATERIAL_NODE_DIFFUSE like with Northstar.
	{
		CHECK(rprMaterialSystemCreateNode(m_matsys,RPR_MATERIAL_NODE_UBERV2,&m_floorMaterial));
		CHECK(rprMaterialNodeSetInputNByKey(m_floorMaterial, RPR_MATERIAL_INPUT_UBER_DIFFUSE_COLOR, m_floorImageMaterial));
	}
	CHECK( rprObjectSetName(m_floorMaterial,"floorMaterial") );
	CHECK( rprShapeSetMaterial(m_shape_floor,m_floorMaterial) );


	// set rendering gamma
	CHECK( rprContextSetParameterByKey1f(m_context, RPR_CONTEXT_DISPLAY_GAMMA , 2.2f ) );

	// increase the max ray iteration
	CHECK( rprContextSetParameterByKey1u(m_context, RPR_CONTEXT_MAX_RECURSION, 10) );

	CHECK( rprContextCreateFrameBuffer(context, m_framebuffer_fmt, &m_framebuffer_desc, &m_frame_buffer) );
	CHECK( rprContextSetAOV(context, RPR_AOV_COLOR, m_frame_buffer) );
	CHECK( rprContextCreateFrameBuffer(context, m_framebuffer_fmt, &m_framebuffer_desc, &m_frame_buffer_res) );


	return newShape;
}

void MatballScene::CameraLook1Shape(int shiftX, int shiftY)
{
	// single matball
	CHECK( rprCameraLookAt(m_camera,
		0.0368774 + (float)shiftX*m_matballGap , -0.929085 + (float)shiftY*m_matballGap  , 0.669423,
		0.0246283 + (float)shiftX*m_matballGap , -0.11254  + (float)shiftY*m_matballGap  , 0.092255,
		0.0f, 0.0f, 1.0f
		) );

}

void MatballScene::CameraLook9Shape()
{
	// 9 matballs :
	CHECK( rprCameraLookAt(m_camera,
		0.0650953 , -2.69557 , 1.69847,
		0.0614207 , -1.96066 , 1.02031,
		0.0f, 0.0f, 1.0f
		) );
}

MatballScene::MATBALL MatballScene::AddMatball(int shiftX, int shiftY, bool createAsInstance)
{
	MatballScene::MATBALL newShape;
	RadeonProRender::float3 shapeListPos = RadeonProRender::float3(m_matballGap*(float)shiftX, m_matballGap*(float)shiftY, 0.0f);


	if ( createAsInstance )
	{
		newShape.base = 0;
		CHECK(rprContextCreateInstance(m_context, m_matballs[0].base, &newShape.base) );  CHECK( rprSceneAttachShape(m_scene, newShape.base));
		newShape.inner = 0;
		CHECK(rprContextCreateInstance(m_context, m_matballs[0].inner, &newShape.inner) ); CHECK(rprSceneAttachShape(m_scene, newShape.inner));
		newShape.outer = 0;
		CHECK(rprContextCreateInstance(m_context, m_matballs[0].outer, &newShape.outer) );  CHECK(rprSceneAttachShape(m_scene, newShape.outer));
	}
	else
	{
		newShape.base = ImportOBJ("../../Resources/Meshes/matball_base.obj",m_scene,m_context);
		newShape.inner = ImportOBJ("../../Resources/Meshes/matball_inner.obj",m_scene,m_context);
		newShape.outer = ImportOBJ("../../Resources/Meshes/matball_outer.obj",m_scene,m_context);
	}

	RadeonProRender::matrix mB = RadeonProRender::translation(shapeListPos);
	CHECK( rprShapeSetTransform(newShape.base, true, &mB.m00));
	CHECK( rprShapeSetTransform(newShape.inner, true, &mB.m00));
	CHECK( rprShapeSetTransform(newShape.outer, true, &mB.m00));

	m_matballs.push_back(newShape);

	return newShape;
	
}



