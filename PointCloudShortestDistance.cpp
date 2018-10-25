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

  // CREATING THE KDTEE OBJECT
  KdTreeFLANN<PointXYZ> kdtree;

  // GIVING THE POINT CLOUD AS THE INPUT FOR FORMING THE TREE
  kdtree.setInputCloud (cloud);

  //CHOOSING A SOURCE POINT FROM THE POINT CLOUD
  PointXYZ source;

  source.x = 1024.0f * rand () / (RAND_MAX + 1.0f);
  source.y = 1024.0f * rand () / (RAND_MAX + 1.0f);
  source.z = 1024.0f * rand () / (RAND_MAX + 1.0f);

  //CHOOSING A DESTINATION POINT FROM THE POINT CLOUD
  PointXYZ destin;

  destin.x = 1024.0f * rand () / (RAND_MAX + 1.0f);
  destin.y = 1024.0f * rand () / (RAND_MAX + 1.0f);
  destin.z = 1024.0f * rand () / (RAND_MAX + 1.0f);



  // K NEAREST SEARCH FOR BOTH SOURCE AND THE DESTINATION POINT UNTIL THERE IS MATCH B/W THE K POINTS OF SOURCE AND THE DESTINATION

  int K = 10;

  vector<int> sourceNPts(K);
  vector<float> sourceNPtsSqUnits(K);

  vector<int> destNPts(K);
  vector<float> destNPtsSqUnits(K);
  int count;
  
  while(1)
 {
	kdtree.nearestKSearch(source,K,sourceNPts,sourceNPtsSqUnits);
	kdtree.nearestKSearch(destin,K,destNPts,destNPtsSqUnits);
	count = 0;
	
	for(int i=0; (i < sourceNPts.size()) ; i++)
     	{
		for(int j=0;j < (destNPts.size());j++)
		{
			if(sourceNPts[i] == destNPts[j])
				count++;
		}
	}
	
	if(count <=5)
		cout<<"THERE WAS NO MATCH OF POINTS FROM SOURCE TO DESTIN"<<endl;
	else
		break;
 }

  return 0;
}
