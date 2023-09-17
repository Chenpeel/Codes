from PIL import Image
from PIL import ImageFilter
im = Image.open('../imags/2.jpg')
e33 = im.filter(ImageFilter.CONTOUR)
e33.save('E(33).jpg')