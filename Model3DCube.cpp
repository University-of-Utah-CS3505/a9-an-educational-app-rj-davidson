#include "Model3DCube.h"

/*
 *TODO
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
 *TODO
*/
std::vector<QImage> Model3DCube::getQImageList(){
    //    QVector<QGraphicsPathItem*> vctrFace0;
    //    QVector<QGraphicsPathItem*> vctrFace1;
    //    QVector<QGraphicsPathItem*> vctrFace2;
    //    QVector<QGraphicsPathItem*> vctrFace3;
    //    QVector<QGraphicsPathItem*> vctrFace4;
    //    QVector<QGraphicsPathItem*> vctrFace5;

    return vctrFaces1DCube;
}

/*
 *TODO
*/
//the cube controller will tell what to display at the same time as the mainwindow cube
void Model3DCube::update3DCube(std::vector<QImage> qImageList)
{

    // the model will need to know the faces hidden and visible
    updateVisibleFace();
    updateHiddenFaces();

    // the model will need to know the way each face needs to look
   //TODO updateFace0(QImage f0,QImage scaled);
    //TODO updateFace1(QImage f1,QImage scaled);
   //TODO updateFace2(QImage f2,QImage scaled);
   //TODO updateFace3(QImage f3,QImage scaled);
   //TODO updateFace4(QImage f4,QImage scaled);
   //TODO updateFace5(QImage f5,QImage scaled);

    // the model will need to save the 3dcube orientation
    updateOrientation();

    emit notify3DCubeView(qImageList);
}

/*
 *TODO
*/
void Model3DCube::updateVisibleFace()
{

}

/*
 *TODO
*/
void Model3DCube::updateHiddenFaces()
{

}

/*
 *TODO
*/
void Model3DCube::updateFace0(QImage f0,QImage scaled)
{

}

/*
 *TODO
*/
void Model3DCube::updateFace1(QImage f1,QImage scaled)
{

}

/*
 *TODO
*/
void Model3DCube::updateFace2(QImage f2,QImage scaled)
{

}

/*
 *TODO
*/
void Model3DCube::updateFace3(QImage f3,QImage scaled)
{

}

/*
 *TODO
*/
void Model3DCube::updateFace4(QImage f4,QImage scaled)
{

}

/*
 *TODO
*/
void Model3DCube::updateFace5(QImage f5,QImage scaled)
{

}

/*
 *TODO
*/
void Model3DCube::updateOrientation(){

}
