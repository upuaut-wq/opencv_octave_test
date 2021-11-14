pkg load image;

i = imread('rice.jpg');
imshow(i);

figure, imhist(i);
figure, imshow(histeq(i));
figure, imhist(histeq(i));

i(10:110, 10:110)=0;
imshow(i);

i2 = imread('rice.jpg');
figure,imshow(i2);

bw = im2bw(i2);
figure,imshow(i2);

se = strel("disk",15,0);
background = imopen(i2,se);

i3 = i2 - background;
figure,imshow(i3);

i4 = imadjust(i3);
figure,imshow(i4);

bw =im2bw(i4);
bw =bwareaopen(bw,50);
bw = imclearborder(bw);
figure, imshow(bw);
