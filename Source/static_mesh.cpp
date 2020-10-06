
#include	"static_mesh.h"
#include	<fbxsdk.h>

using namespace fbxsdk;

#include	<vector>
#include	<functional>

#include	"resource_manager.h"



void StaticMesh::_fbxInit(ID3D11Device* device, const char* fbx_filename)
{
	// Create the FBX SDK manager
	FbxManager* manager = FbxManager::Create();

	// Create an IOSettings object. IOSROOT is defined in Fbxiosettingspath.h.
	manager->SetIOSettings(FbxIOSettings::Create(manager, IOSROOT));

	// Create an importer.
	FbxImporter* importer = FbxImporter::Create(manager, "");

	// Initialize the importer.
	bool import_status = false;
	import_status = importer->Initialize(fbx_filename, -1, manager->GetIOSettings());
	if(!import_status)
	{
		assert(importer->GetStatus().GetErrorString());
		return;
	}

	// Create a new scene so it can be populated by the imported file.
	FbxScene* scene = FbxScene::Create(manager, "");

	// Import the contents of the file into the scene.
	import_status = importer->Import(scene);
	if(!import_status)
	{
		assert(importer->GetStatus().GetErrorString());
		return;
	}

	// Convert mesh, NURBS and patch into triangle mesh
	fbxsdk::FbxGeometryConverter geometry_converter(manager);
	geometry_converter.Triangulate(scene, /*replace*/true);

	// Fetch node attributes and materials under this node recursively. Currently only mesh.	
	std::vector<FbxNode*> fetched_meshes;
	std::function<void(FbxNode*)> traverse = [&](FbxNode* node) {
		if (node) {
			FbxNodeAttribute *fbx_node_attribute = node->GetNodeAttribute();
			if (fbx_node_attribute) {
				switch (fbx_node_attribute->GetAttributeType()) {
				case FbxNodeAttribute::eMesh:
					fetched_meshes.push_back(node);
					break;
				}
			}
			for (int i = 0; i < node->GetChildCount(); i++)
				traverse(node->GetChild(i));
		}
	};
	traverse(scene->GetRootNode());

	FbxMesh *fbx_mesh = fetched_meshes.at(0)->GetMesh();  // Currently only one mesh.

	// Fetch mesh data
	std::vector<Vertex> vertices;	// Vertex buffer
	std::vector<u_int> indices;		// Index buffer
	u_int vertex_count = 0;

	const FbxVector4 *array_of_control_points = fbx_mesh->GetControlPoints();
	const int number_of_polygons = fbx_mesh->GetPolygonCount();
	for (int index_of_polygon = 0; index_of_polygon < number_of_polygons; index_of_polygon++) {
		for (int index_of_vertex = 0; index_of_vertex < 3; index_of_vertex++) {
			Vertex vertex;
			const int index_of_control_point = fbx_mesh->GetPolygonVertex(index_of_polygon, index_of_vertex);
			vertex.pos.x = static_cast<float>(array_of_control_points[index_of_control_point][0]);
			vertex.pos.y = static_cast<float>(array_of_control_points[index_of_control_point][1]);
			vertex.pos.z = static_cast<float>(array_of_control_points[index_of_control_point][2]);

			FbxVector4 normal;
			fbx_mesh->GetPolygonVertexNormal(index_of_polygon, index_of_vertex, normal);
			vertex.normal.x = static_cast<float>(normal[0]);
			vertex.normal.y = static_cast<float>(normal[1]);
			vertex.normal.z = static_cast<float>(normal[2]);

			vertices.push_back(vertex);
			indices.push_back(vertex_count);
			vertex_count += 1;
		}
	}
	manager->Destroy();

	CreateBuffers(device, vertices.data(), (UINT)vertices.size(), indices.data(), (UINT)indices.size());
}
