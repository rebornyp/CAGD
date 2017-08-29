#include "surfacepart.h"
#include "ui_surfacepart.h"

SurfacePart::SurfacePart(QGLWidget *parent) : //构造函数
    QGLWidget(parent),
    ui(new Ui::SurfacePart)
{
    tra = -1000.0;
    xRot = yRot = zRot = 0.0;
    oldPoint = QPoint(0, 0);
    isInputting = false;
    isRead = false;
    isDraw = false;
    trax = -200, tray = 100;

    ui->setupUi(this);
}

SurfacePart::~SurfacePart()
{
    delete ui;
}

//初始化函数
void SurfacePart::initializeGL() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glShadeModel(GL_SMOOTH);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
}

//自适应函数
void SurfacePart::resizeGL(int width, int height) {
    glViewport( 0, 0, (GLint)width, (GLint)height );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective( 45, (GLfloat)width/(GLfloat)height, 0.1, 9999.0 );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
}

//绘图主函数
void SurfacePart::paintGL()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glLoadIdentity();
    glTranslatef(trax,  tray, tra);
    gluLookAt(0,0,0.0,0.0,0.0,1.0,0.0,-1.0,0.0);

    glRotatef(xRot, 1.0, 0.0, 0.0);
    glRotatef(yRot, 0.0, 1.0, 0.0);
    glRotatef(zRot, 0.0, 0.0, 1.0);

    glColor3f(0.0, 0.0, 0.0);
    glPointSize(10.0f);

    if(!pointVector.isEmpty()) {
        glColor3f(0.0,0.0,1.0);
        glPointSize(10.0f);
        for(int i=0; i<pointVector.size(); i++) {
            drawPoint(pointVector.at(i));
        }
        glColor3f(1.0,0.0,1.0);
        for(int i=0; i<5; i++) {
            for(int j=0; j<4; j++) {
                drawLines(p[i][j], p[i][j+1]);
            }
        }
        for(int i=0; i<5; i++) {
            for(int j=0; j<4; j++) {
                drawLines(p[j][i], p[j+1][i]);
            }
        }
        if(isInputting == true) {
            glColor3f(0.0,0.0,0.0);
            glPointSize(2.0f);

            int u = 0, v = 0;
            Point temp, base;
            double Ut = 0.0, Vt = 0.0;
            while(u <= 100) {
                v = 0;
                while(v <= 100) {
                    Ut = u/100.0, Vt = v/100.0;
                    if(u == 0)
                        Ut += 0.001;
                    if((u!=0) && (v==0))
                        Vt += 0.001;
                    temp = countPoint(Ut, Vt);
                    if(v != 0) {
                        glColor3f(0.0,0.0,0.0);
                        drawLines(base, temp);
                    }
                    base = temp;
                    v += 2;
                }
                u += 2;
            }
            v = 0;
            Ut = 0.0, Vt = 0.0;
            glColor3f(0.0,0.0,0.0);
            while(v <= 100) {
                u = 0;
                while(u <= 100) {
                    Ut = u/100.0, Vt = v/100.0;
                    if(v == 0)
                        Vt += 0.001;
                    if((Vt!=0) && (Ut==0))
                        Ut += 0.001;
                    temp = countPoint(Ut, Vt);
                    if(u != 0) {
                        drawLines(base, temp);
                    }
                    base = temp;
                    u += 2;
                }
                v += 2;
            }
        }
    }
    isInputting = false;

    glColor3f(0.0,0.0,1.0);
    glBegin(GL_LINES);
        glVertex3f(500.0, 0.0, 0.0);
        glVertex3f(0.0, 0.0, 0.0);
    glEnd();
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINES);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, 500.0, 0.0);
    glEnd();
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_LINES);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, 0.0, -500.0);
    glEnd();

}

//绘制点
void SurfacePart::drawPoint(double x, double y, double z) {
    glBegin(GL_POINTS);
      glVertex3f(x, y, z);
    glEnd();
}

//求算曲面上的点
Point SurfacePart::countPoint(double u, double v) {
    double x = 0.0, y = 0.0, z = 0.0;
    double th1, th2;
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            th1 = Basisfun(i, info->uk, ut, u);
            th2 = Basisfun(j, info->vk, vt, v);
            th1 = th1 * th2;
            x += p[i][j].x * th1;
            y += p[i][j].y * th1;
            z += p[i][j].z * th1;
        }
    }
    return Point(x, y, z);
}

//求算B样条基函数的方法1
double SurfacePart::Basisfun(int i, int k, double *knot, double u)
{
    double x1,x2,y1,y2;
    x1=0;x2=0;y1=0;y2=0;
    if (k==0)									//若阶数为1
    {
        if ((u>knot[i])&&(u<=knot[i+1]))		//若参数u落在[ui,ui+1]节点区间内
            return 1;
        else
            return 0;
    }
    else if(k>0)								//若阶数大于1
    {
        if (knot[i+k]!=knot[i])					//若ui+k-1与ui为非重节点
        {
            x1=Basisfun(i,k-1,knot,u);
            x2=(u-knot[i])*x1/(knot[i+k]-knot[i]);	//计算B样条基函数递归定义的第一项
        } else if(knot[i+k]==knot[i])
            x2=0;
        if (knot[i+k+1]!=knot[i+1])
        {
            y1=Basisfun(i+1,k-1,knot,u);
            y2=(knot[i+k+1]-u)*y1/(knot[i+k+1]-knot[i+1]);//计算B样条基函数递归定义的第二项
        }
        else if(knot[i+k+1]==knot[i+1])
            y2=0;
        return x2+y2;						//计算B样条基函数递归定义的第一项和第二项之和
    }
    return 1;
}

//求算B样条基函数的方法2
double SurfacePart::N(double u, int i, int k, double *arr) {
    double Val=0.0;
    double val1=0.0;
    double val2=0.0;
    if(k == 0 )
    {
        if(u<arr[i]||u>arr[i+1])
        return Val;
        else
        {
            Val=1.0;
            return Val;
        }
    }
    if(k>0)
    {

        if(u<arr[i]||u>arr[i+k+1])
            return Val;
        else
        {
            double alpha = 0.0;
            double beta = 0.0;
            double dTemp = 0.0;
            dTemp = arr[i+k] - arr[i];
            if(dTemp < 1e-5)
                alpha = 0.0;
            else
                alpha = (u - arr[i]) / dTemp;
            dTemp = arr[i+k+1] - arr[i+1];
            if(dTemp < 1e-5)
                beta = 0.0;
            else
                beta = (arr[i+k+1]-u) / dTemp;
            val1 = alpha * N(u,i,k-1, arr);
            val2 = beta * N(u,i+1,k-1, arr);
            Val = val1+val2;
        }
    }
    return Val;
}

//绘制点的方法
void SurfacePart::drawPoint(Point a) {
    glBegin(GL_POINTS);
      glVertex3f(a.x, a.y, a.z);
    glEnd();
}

//绘制直线的方法
void SurfacePart::drawLines(Point a, Point b) {
    glBegin(GL_LINES);
        glVertex3f(a.x, a.y, a.z);
        glVertex3f(b.x, b.y, b.z);
    glEnd();
}

//*********
void SurfacePart::clcFunc()
{
    isInputting = false;
    isRead = false;
    updateGL();
}

//拿到绘图命令后绘图的槽函数
void SurfacePart::draw(surfaceInfo *i)
{
    if(!isRead)
        return;
    info = i;
    isDraw = true;
    getInfo();
    isInputting = true;
    updateGL();
}

//获取控制面板的信息
void SurfacePart::getInfo()
{
    ut = new double[5+info->uk+1];
    vt = new double[5+info->vk+1];
    deal(ut, info->uk, info->uIndex);
    deal(vt, info->vk, info->vIndex);

}

//读取文件，包含打开.txt文件等然后处理字符串等操作
void SurfacePart::applyRead() {
    QString file_full, file_name, file_path;
    QFileInfo fi;

    file_full = QFileDialog::getOpenFileName(this);

    fi = QFileInfo(file_full);
    file_name = fi.fileName();
    file_path = fi.absolutePath();
    QFile f(file_path+"/"+file_name);

    if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"Open failed.";
        return ;
    }

    isRead = true;
    QTextStream txtInput(&f);
    QString lineStr;
    QStringList list;
    double x, y, z;
    pointVector.clear();

    while(!txtInput.atEnd())
    {
        lineStr = txtInput.readLine();
        lineStr = lineStr.mid(11, lineStr.length());
        lineStr = lineStr.replace(")", "");
        list = lineStr.split(QRegExp("[,]"));
        x = list.at(0).toDouble();
        y = list.at(1).toDouble();
        z = list.at(2).toDouble();
        pointVector.push_back(Point(x, y, z));
    }

    f.close();

    int k = 0;
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            p[j][i] = pointVector.at(k);
            k ++;
        }
    }
    updateGL();
}

//清屏的函数
void SurfacePart::clc() {
    pointVector.clear();
    isDraw = false;
    tra = -1000.0;
    xRot = yRot = zRot = 0.0;
    isRead = false;
    isInputting = false;
    updateGL();
}

//处理节点矢量的函数
void SurfacePart::deal(double* temp, int a, int b) {
    int n = 5, k = a;
    if(b == 0) {
        for(int i=0; i<6+a; i++) {
            if(i < a+1) {
                temp[i] = 0;
            }
            else if(i > 5-1) {
                temp[i] = 1;
            }
            else {
                temp[i] = 1.0 * (i - a) / (5 - a);
            }
        }
    } else if(b == 1) {
        double s = 1.0 / (n - k);
        temp[0] = 0 - k * s;
        for(int i=1; i<n+k+1; i++) {
            temp[i] = temp[0] + i * s;
        }
    }
}

//鼠标点击事件
void SurfacePart::mousePressEvent(QMouseEvent *event) {
    if(event->buttons()==Qt::LeftButton) {
        oldPoint = event->pos();
    }
}

//鼠标移动事件
void SurfacePart::mouseMoveEvent(QMouseEvent *e) {
    if(e->buttons()==Qt::LeftButton) {
        if(isDraw == true)
            isInputting = true;
        QPoint temPoint = e->pos()- oldPoint;
        xRot += temPoint.y() * 0.5;
        yRot += temPoint.x() * 0.5;
        oldPoint = e->pos();
        updateGL();
    }
}

//滚轮事件
void SurfacePart::wheelEvent(QWheelEvent *e) {
    tra += e->delta();
    if(isDraw == true)
        isInputting = true;
    updateGL();
}
