import numpy as np

def readRaw(img_path,height,width,channel=1):
    with open(img_path,'rb') as obj:
        data_bytes=obj.read()
    img=[x for x in data_bytes]
    if channel>1:
        return np.array(img).reshape([height,width,channel])
    else:
        return np.array(img).reshape([height,width])


def getPixel(img,x,y,z=1):
    s=img.shape
    [height,width]=s[0:2]
    if len(s)>2:
        channel=s[2]
    else:
        channel=1
    
    if x<0:
        x=-x
    if x>height-1:
        x=2*(height-1)-x
    if y<0:
        y=-y
    if y>width-1:
        y=2*(width-1)-y
    if channel>1:
        return img[x,y,z]
    else:
        return img[x,y]
    
def do_filter(I,Filter):
    [height,width]=I.shape
    [h,w]=Filter.shape
    G=np.zeros((height,width))
    
    for i in range(height):
        for j in range(width):
            t=0
            for x in range(h):
                for y in range(w):
                    t+=getPixel(I,i+x-h//2,j+y-w//2)*getPixel(Filter,x,y)
            G[i,j]=t
    return G
            