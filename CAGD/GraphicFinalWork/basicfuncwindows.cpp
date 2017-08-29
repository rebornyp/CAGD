#include "basicfuncwindows.h"
#include "ui_basicfuncwindows.h"


basicFuncWindows::basicFuncWindows(QGLWidget *parent) :
    QGLWidget(parent),
    ui(new Ui::basicFuncWindows)
{
    ui->setupUi(this);
    draw = false;

}

basicFuncWindows::~basicFuncWindows()
{
    delete ui;
}

void basicFuncWindows::getInfo(Info *a)
{
    info = a;
    draw = true;
    //各种对所将要绘制的曲线类型做判断了后的节点矢量的求算
    if(info->cb == 0) {
        int n = info->num, k = info->le;
        t = new double[n + k + 1];
        if(info->type == 0) {
            for(int i=0; i<n+k+1; i++) {
                if(i < k+1)
                    t[i] = 0;
                else if(i > n-1)
                    t[i] = 1;
                else {
                    t[i] = 1.0 * (i - k) / (n-k);
                }
            }
        } else if(info->type == 1) {
            double s = 1.0 / (n + k);
            t[0] = 0;
            for(int i = 1;i < n+k+1;i++) {
                t[i] = t[0] + i * s;
            }
        } else if(info->type == 2) {
            int linesNum = n - 1;
            double *l = new double[linesNum];
            double count = 0, s = 0;
            for(int i=0; i<linesNum; i++) {
                l[i] = getDistance(info->qvp->at(i), info->qvp->at(i + 1));
                count += l[i];
            }
            if(k % 2 == 0) {
                for(int i=0; i<=k; i++) {
                    t[i] = 0;
                    t[i+n] = 1;
                }
                for(int i=1; i<n-k; i++) {
                    s = 0;
                    for(int j=1; j<k/2+i; j++)
                        s += l[j];
                    t[k+i]=(s + l[k/2+i] / 2) / count;
                }
            } else {
                for(int i=0; i<=k; i++) {
                    t[i] = 0;
                    t[i+n] = 1;
                }
                for(int i=1; i<n-k; i++) {
                    s=0;
                    for(int j=1; j<(k+1)/2+i; j++)
                        s += l[j];
                    t[k+i] = s / count;
                }
            }
        } else if(info->type == 3) {
            int linesNum = n - 1;
            double *l = new double[linesNum];
            double count = 0, s = 0;
            for(int i=0; i<linesNum; i++) {
                l[i] = getDistance(info->qvp->at(i), info->qvp->at(i + 1));
                count += l[i];
            }
            for(int i=0; i<=k; i++)
            {
                t[i] = 0;
                t[i+n] = 1;
            }
            s = 0;
            for(int i=k+1; i<=n; i++)
            {
                for(int j=i-k; j<=i-1; j++)
                {
                    s += l[j-1];
                }
            }
            double li;
            for(int i=k+1; i<n; i++)
            {
                li = 0;
                for(int j=i-k; j<=i-1; j++)
                {
                    li += l[j-1];
                }
                t[i] = li / s;
                t[i] += t[i-1];
            }
        } else if(info->type == 4) {
            for(int i=0; i<=n+k; i++) {
                if(i <= k) {
                    t[i] = 0;
                } else if(i >= n) {
                    t[i] = 1;
                } else {
                    t[i] = ((i-1) / k) / double((n - 1)/k);
                }
            }
        }
    } else {
        int n = info->qvp->size();
        int k = n -  1;
        t = new double[n + k + 1];
        for(int i=0; i<n+k+1; i++) {
            if(i < k+1)
                t[i] = 0;
            else if(i > n-1)
                t[i] = 1;
            else {
                t[i] = 1.0 * (i - k) / (n-k);
            }
        }
    }
    updateGL();
}

//清屏的方法
void basicFuncWindows::clc()
{
    draw = false;
    updateGL();
}

//获取距离的方法
double basicFuncWindows::getDistance(QPoint a, QPoint b)
{
    return qSqrt(qPow(a.x() - b.x(), 2) + qPow(a.y() - b.y(), 2));
}

//初始化的函数
void basicFuncWindows::initializeGL()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glShadeModel(GL_SMOOTH);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
}

void basicFuncWindows::resizeGL(int width, int height) {
    glViewport( 0, 0, (GLint)width, (GLint)height );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D(-0.2, 1.2, -0.2, 1.2);
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
}

//绘制主函数
void basicFuncWindows::paintGL() {
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glLoadIdentity();
    gluLookAt(0,0,0.0,0.0,0.0,-1.0,0.0,1.0,0.0);
    if(draw == true) {

        if(info == NULL)
            return;
        double step;
        double value = 0;
        if(info->cb == 0) {
            double tempx = 0, tempy = 0;
            for(int i=0; i<info->num; i++) {
                step = 0;
                while(step <= 1) {
                    glColor3f(0.0, 0.0, 0.0);
                    glPointSize(2.0f);
                    value = GetBaseFunVal(step, i, info->le);
                    if(step == 0) {
                        drawPoint(step, value);
                    }
                    else {
                        drawPoint(tempx, tempy);
                        drawLine(tempx, tempy, step, value, 2);
                    }
                    tempx = step;
                    tempy = value;
                    step += 0.001;
                }
            }

            QFont BeFont;
            BeFont.setPointSize(10);
            int n = info->num - 1, k = info->le;
            if(info->type != 1) {
                if(info->type != 4) {
                    renderText(-0.08, 0.05, 0,"u[0-  ]", BeFont);
                    renderText(1, 0.05, 0,"u[  -  ]", BeFont);
                    renderText(1.02, 0.05, 0,QString::number(info->num), BeFont);
                    renderText(1.05, 0.05, 0,QString::number(info->num + info->le), BeFont);
                    renderText(-0.04, 0.05, 0,QString::number(info->le), BeFont);

                    for(int i=k+1; i<n+1; i++) {
                        renderText(t[i], -0.11, 0,QString::number(i), BeFont);
                        renderText(t[i]-0.017, -0.11, 0,"u[  ]", BeFont);
                    }
                }
            } else {
                for(int i=0; i<n+2+k; i++) {
                    renderText(t[i], -0.11, 0,QString::number(i), BeFont);
                    renderText(t[i]-0.017, -0.11, 0,"u[  ]", BeFont);
                }
            }

        } else {
            int total = info->qvp->size();
            double tempx = 0, tempy = 0;
            for(int i=0; i<total; i++) {
                step = 0;
                while(step <= 1) {
                    glColor3f(0.0, 0.0, 0.0);
                    glPointSize(2.0f);
                    value = GetBaseFunVal(step, i, total-1);
                    if(step == 0) {
                        drawPoint(step, value);
                    }
                    else {
                        drawPoint(tempx, tempy);
                        drawLine(tempx, tempy, step, value, 2);
                    }
                    tempx = step;
                    tempy = value;

                    step += 0.001;
                }
            }

            int numberDot = info->qvp->size();
            QFont BezierFont;
            BezierFont.setPointSize(10);
            renderText(0, -0.12, 0,"u[0-  ]", BezierFont);
            renderText(0.04, -0.12, 0,QString::number(numberDot-1), BezierFont);
            renderText(1, -0.12, 0,"u[  -  ]", BezierFont);
            renderText(1.05, -0.12, 0,QString::number(2*numberDot-1), BezierFont);
            renderText(1.02, -0.12, 0,QString::number(numberDot), BezierFont);
        }



    }
    QFont font;
    font.setPointSize(15);
    glColor3f(0.0, 0.0, 0.0);
    font.setFamily("MS Shell Dlg 2"); // Tahoma 宋体
    renderText(0.3, 1.0, 0,"the Base functions", font);
    font.setPointSize(10);
    renderText(-0.02, -0.12, 0,"0", font);
    renderText(0.98, -0.12, 0,"1", font);
    renderText(1.15, -0.12, 0,"x", font);
    renderText(-0.02, 1, 0,"y", font);
    draw = false;

    glColor3f(0.0, 1.0, 0.0);
    glPointSize(1.0f);
    drawLine(QPoint(-99, 0), QPoint(99, 0), 1);
    drawLine(QPoint(0, -99), QPoint(0, 99), 1);
    glColor3f(1.0, 0.0, 1.0);
    drawLine(QPoint(1, -99), QPoint(1, 99), 1);


}

void basicFuncWindows::drawPoint(QPoint a) {
    glBegin(GL_POINTS);
      glVertex2f(a.x(), a.y());
    glEnd();
}

void basicFuncWindows::drawPoint(double x, double y) {
    glBegin(GL_POINTS);
      glVertex2f(x, y);
    glEnd();
}

void basicFuncWindows::drawLine(QPoint a, QPoint b, double h) {
    glLineWidth(h);
    glBegin(GL_LINES);
            glVertex2f(a.x(), a.y());
            glVertex2f(b.x(), b.y());
    glEnd();
}

void basicFuncWindows::drawLine(double ax, double ay, double bx, double by, double h) {
    glLineWidth(h);
    glBegin(GL_LINES);
            glVertex2f(ax, ay);
            glVertex2f(bx, by);
    glEnd();
}

//绘制基函数的方法
double basicFuncWindows::GetBaseFunVal(double u, int i, int k) {
    double Val=0.0;
    double val1=0.0;
    double val2=0.0;
    if(k == 0 )
    {
        if(u<t[i]||u>t[i+1])
        return Val;
        else
        {
            Val=1.0;
            return Val;
        }
    }
    if(k>0)
    {

        if(u<t[i]||u>t[i+k+1])
            return Val;
        else
        {
            double alpha = 0.0;
            double beta = 0.0;
            double dTemp = 0.0;
            dTemp = t[i+k] - t[i];
            if(dTemp < 1e-5)
                alpha = 0.0;
            else
                alpha = (u - t[i]) / dTemp;
            dTemp = t[i+k+1] - t[i+1];
            if(dTemp < 1e-5)
                beta = 0.0;
            else
                beta = (t[i+k+1]-u) / dTemp;
            val1 = alpha*GetBaseFunVal(u,i,k-1);
            val2 = beta*GetBaseFunVal(u,i+1,k-1);
            Val = val1+val2;
        }
    }
    return Val;
}


