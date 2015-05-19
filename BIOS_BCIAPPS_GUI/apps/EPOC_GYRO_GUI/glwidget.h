#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QtOpenGL\qgl.h>
#include <qtimer.h>
#include <glut.h>

class GLWidget : public QGLWidget
{
	Q_OBJECT
public:
	explicit GLWidget(QWidget *parent = 0);

	void initializeGL();
	void paintGL();
	void updateDisplay(void);
	void resizeGL(int w, int h);

signals:

public slots:

private:
	QTimer timer;


};


#endif // GLWIDGET_H