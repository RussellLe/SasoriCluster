#include "stdafx.h"
#include "cluster_launcher.h"

using namespace std;

int main()
{
    sasori::ClusterLauncher launcher;
    launcher.launch("./testconfig");
    return 0;
}