#include "Model3DCube.h"

/*
 *
*/
Model3DCube::Model3DCube(QWidget *parent,CubeController *controller)
{

}

/*
 *
*/
//~Model3DCube::Model3DCube(){
//    delete
//}

/*
 *
*/
std::vector<QImage> Model3DCube::getQImageList(){
    //    QVector<QGraphicsPathItem*> vctrFace0;
    //    QVector<QGraphicsPathItem*> vctrFace1;
    //    QVector<QGraphicsPathItem*> vctrFace2;
    //    QVector<QGraphicsPathItem*> vctrFace3;
    //    QVector<QGraphicsPathItem*> vctrFace4;
    //    QVector<QGraphicsPathItem*> vctrFace5;

    return
}

/*
 *
*/
//the cube controller will tell what to display at the same time as the mainwindow cube
void Model3DCube::update3DCube(std::vector<QImage> qImageList)
{

//    QVector<QGraphicsPathItem*> vctrFace0;
//    QVector<QGraphicsPathItem*> vctrFace1;
//    QVector<QGraphicsPathItem*> vctrFace2;
//    QVector<QGraphicsPathItem*> vctrFace3;
//    QVector<QGraphicsPathItem*> vctrFace4;
//    QVector<QGraphicsPathItem*> vctrFace5;
    emit notify3DCubeView(qImageList);
}

/*
 *
*/
void Model3DCube::updateLeftCubeData()
{

}

/*
 *
*/
void Model3DCube::updateRightCubeData()
{

}

/*
 *
*/
void Model3DCube::updateTopCubeData()
{

}

/*
 *
*/
void Model3DCube::updateHiddenFaces()
{

}

/*
 *
*/
void Model3DCube::updateFace0(QImage f0,QImage scaled)
{

}

/*
 *
*/
void Model3DCube::updateFace1(QImage f1,QImage scaled)
{

}

/*
 *
*/
void Model3DCube::updateFace2(QImage f2,QImage scaled)
{

}

/*
 *
*/
void Model3DCube::updateFace3(QImage f3,QImage scaled)
{

}

/*
 *
*/
void Model3DCube::updateFace4(QImage f4,QImage scaled)
{

}

/*
 *
*/
void Model3DCube::updateFace5(QImage f5,QImage scaled)
{

}
