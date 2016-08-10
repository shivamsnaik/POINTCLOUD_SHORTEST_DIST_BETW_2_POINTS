#include <pcl/point_cloud.h>
#include <pcl/kdtree/kdtree_flann.h>

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;
using namespace pcl;

int
main (int argc, char** argv)
{
	
  srand (time (NULL));

  PointCloud<PointXYZ>::Ptr cloud(new PointCloud<PointXYZ>());

  // Generate pointcloud data
  cloud->width = 100;
  cloud->height = 1;
  cloud->points.resize (cloud->width * cloud->height);

  for (size_t i = 0; i < cloud->points.size (); ++i)
  {
    cloud->points[i].x = 1024.0f * rand () / (RAND_MAX + 1.0f);
    cloud->points[i].y = 1024.0f * rand () / (RAND_MAX + 1.0f);
    cloud->points[i].z = 1024.0f * rand () / (RAND_MAX + 1.0f);
  }

  KdTreeFLANN<PointXYZ> kdtree;

  kdtree.setInputCloud (cloud);

  PointXYZ source;

  source.x = 1024.0f * rand () / (RAND_MAX + 1.0f);
  source.y = 1024.0f * rand () / (RAND_MAX + 1.0f);
  source.z = 1024.0f * rand () / (RAND_MAX + 1.0f);

	
  PointXYZ destin;

  destin.x = 1024.0f * rand () / (RAND_MAX + 1.0f);
  destin.y = 1024.0f * rand () / (RAND_MAX + 1.0f);
  destin.z = 1024.0f * rand () / (RAND_MAX + 1.0f);



  // K nearest neighbor search

  int K = 10;

  vector<int> sourceNPts(K);
  vector<float> sourceNPtsSqUnits(K);

  vector<int> destNPts(K);
  vector<float> destNPtsSqUnits(K);

  while(1)
 {

 }

  return 0;
}