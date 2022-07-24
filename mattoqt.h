#ifndef MATTOQT_H
#define MATTOQT_H
#include <opencv2/opencv.hpp>
#include <QImage>

void matToQimage(cv::InputArray image, QImage& out);
void qimageToMat(const QImage& image, cv::OutputArray out);

#endif // MATTOQT_H
