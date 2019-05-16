import cv2
import numpy as np
import matplotlib.pyplot as plt
from PIL import Image
 
f = '1.jpg'
average_square = (5, 5)
sigma_x = 0
k=20
line_average = (9, 9)
line_sigma_x = 0
multi_w = 0.5
paint_w = 0.9
gamma = 1.5
method = 2

image = cv2.imread(f, 1)
file = 'test'
ext = '.jpg'
 
image_blurring = cv2.GaussianBlur(image, average_square, sigma_x)
w , h , channel = image_blurring.shape
image_reshape = np.zeros((w , h ,3), np.uint8)
for i in range(w):
    for j in range(h):
        r , g , b = image_blurring[i , j]
        image_reshape[i , j] = (round(r/k)*k , round(g/k)*k , round(b/k)*k)
paint = cv2.GaussianBlur(image_reshape, average_square, sigma_x)
cv2.imwrite(file + "_paint" + ext, paint)
 
image_preprocessed  = cv2.cvtColor(cv2.GaussianBlur(image, line_average, line_sigma_x), cv2.COLOR_BGR2GRAY)
if method == 1:
    x = cv2.Sobel(image_preprocessed,cv2.CV_16S,1,0,ksize=5)  
    y = cv2.Sobel(image_preprocessed,cv2.CV_16S,0,1,ksize=5)  
    absX = cv2.convertScaleAbs(x) 
    absY = cv2.convertScaleAbs(y)  
    image_binary = cv2.addWeighted(absX,0.5,absY,0.5,0)  
    image_binary = cv2.GaussianBlur(image_binary, average_square, sigma_x)
    image_binary = cv2.adaptiveThreshold(image_binary,255,cv2.ADAPTIVE_THRESH_GAUSSIAN_C,cv2.THRESH_BINARY_INV,11,2)
    multi_w = 0.1
else:
    image_binary = cv2.Canny(image_preprocessed, threshold1 = 50, threshold2 = 55) 
    image_binary = cv2.GaussianBlur(image_binary, average_square, sigma_x)
    res, image_binary = cv2.threshold(image_binary, 90, 255, cv2.THRESH_BINARY_INV)

cv2.imwrite(file + "_line" + ext, image_binary)

w , h , channel = paint.shape
result = np.zeros((w , h ,3), np.uint8)
for i in range(w):
    for j in range(h):
        r,g,b = paint[i,j]
        if image_binary[i,j] == 0:
            r2 = 0
            g2 = 0
            b2 = 0
        else:
            r2 = 255
            g2 = 255
            b2 = 255
        img_r = int(round(((r*r2)/255)))
        img_g = int(round(((g*g2)/255)))
        img_b = int(round(((b*b2)/255)))
        result[i,j] = (img_r,img_g,img_b)
 
d = cv2.addWeighted(result, multi_w, paint, paint_w, gamma)
 
cv2.imwrite(file + "_output" + ext, d)
cv2.imshow('result' , d)
cv2.waitKey(0)