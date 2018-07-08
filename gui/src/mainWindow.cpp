//
// Created by jianping on 18-4-7.
//

#include "mainWindow.h"
#include "dlg_extract.h"
#include "dlg_dataManage.h"
#include "dlg_pointcloud.h"
#include <iostream>
using namespace std;

void mainWindow::show_hey()
{
    cout<<"feature extract dialog has been shown";
    dlg_hey t;
    t.exec();
}
void mainWindow::show_log2()
{
    cout<<"data manage dialog has been shown\n";
    dialog2 a;
    a.exec();
}

void mainWindow::show_dlg_pointcloud()
{
    dlg_pointcloud a;
    a.exec();
}