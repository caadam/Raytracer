#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <ctime>

#include "Scene.h"
#include "Color.h"

#include "Maths/Vector.h"
#include "Maths/Ray.h"
#include "Maths/Intersection.h"
#include "Export/Image.h"
#include "Export/Image/Tga.h"
#include "Camera/Camera.h"
#include "Geometry/Object.h"
#include "Geometry/Solid/Plane.h"
#include "Geometry/Solid/Sphere.h"
#include "Geometry/Polygon/Triangle.h"
#include "Lighting/Light.h"
#include "Shading/Material.h"
#include "Rendering/Unbiased/RayTracer.h"

using namespace std;

int main(int argc, char **argv)
{
	string outfile_name("test.tga");
	Scene scene;

	scene.camera_ = new Camera();
	scene.camera_->origin_coord_ = Vector(0, 0, 10);
	scene.camera_->plane_center_coord_ = Vector(0, 16, 0);
	scene.camera_->plane_width_ = 18;
	scene.camera_->plane_height_ = 12;

	scene.ambient_ = Color(1, 1, 1);

	Light *light = new Light();
	light->origin_coord_ = Vector(2.5, 10, 5);
	light->color_ = Color(1, 1, 1);
	light->intensity_ = 7;
	light->radius_ = 0.2;

	scene.lights_.push_back(light);

	Material *mat = new Material();
	mat->cDiffuse = Color(1, 1, 1);
	mat->cReflection = Color(1, 1, 1);
	mat->cSpecular = Color(1, 1, 1);
	mat->kAmbient = 0.01;
	mat->kDiffuse = 1.0;
	mat->kOcclusion = 0.02;
	mat->kReflection = 0.3;
	mat->kSpecular = 1.0;
	mat->shininess = 50;

	scene.objects_.push_back(new Sphere(Vector(-5, 10, 1), 1, mat));
	scene.objects_.push_back(new Sphere(Vector(-2.5, 10, 1), 1, mat));
	scene.objects_.push_back(new Sphere(Vector(0, 15, 1), 1, mat));
	scene.objects_.push_back(new Sphere(Vector(4.5, 13.5, 1), 1, mat));
	scene.objects_.push_back(new Sphere(Vector(5, 10, 1), 1, mat));

	// plane (origin) (normal_unit_vector) material_name
	scene.objects_.push_back(new Plane(Vector(0, 0, 0), Vector(0, 0, 1), mat));

	// triangle (point0) (point1) (point2) material_name
	scene.objects_.push_back(new Triangle(Vector(0.8, 14, 3), Vector(1.5, 13, 0), Vector(3, 14, 1.5), mat));

	// qualityparams max_reflections softlight_quality occlusion_quality
	scene.max_reflections_ = 5;
	scene.softlight_quality_ = 22;
	scene.occlusion_quality_ = 100;

	// render width height outfile
	//render 900 600 sample_scene.png
	RayTracer renderer = RayTracer();
	renderer.scene = &scene;

	std::cout << "Rendering..." << std::endl;

	time_t start = time(0);
	Tga output = Tga(900,600);
	renderer.render(900, 600, &output);

	std::cout << "Rendering finished in " << difftime(time(0), start) << " seconds." << std::endl;

	std::cout << "Writing to " << outfile_name << "." << std::endl;

	output.Save(outfile_name.c_str(), true);

	exit(EXIT_SUCCESS);
}