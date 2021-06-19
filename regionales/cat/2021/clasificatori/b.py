from jutge import read
from PIL import Image, ImageDraw

n, s = read(int, int)

x = 0
y = 0

img = Image.new("RGB", (n * s * (n + 1)//2, n * s * (n + 1)//2), "Blue")
dib = ImageDraw.Draw(img)

def px (k):
    return k * s

def inp (k, cn):
    if cn:
        k += 1
    if k % 2 == 0:
        return "Yellow"
    else:
        return "Red"

def par (k, cn):
    if cn:
        k += 1
    if k % 2 == 0:
        return "Lime"
    else:
        return "Blue"

cnp = False
cni = False
        
for i in range(n, 0, -1):
    if i % 2 == 1:
       for j in range(i//2 + 1):
           dib.rectangle([(j * px(i), y), ( j * px(i) + px(i) - 1), y + px(i) - 1], inp(j, False))
       y += px(i);
       for j in range(i//2):
           dib.rectangle([((i//2) * px(i), y + j * px(i)), ((i//2 + 1) * px(i) - 1), y + (j + 1) * px(i) - 1], inp(j, cni))
       if cni:
           cni = False
       else:
           cni = True
    else:
       offx = px(i)/2
       for j in range(i//2):
           dib.rectangle([(offx + j * px(i), y) , (offx + j * px(i) + px(i) - 1, y + px(i) - 1)], par(j, False))
       y += px(i);
       for j in range(i//2 - 1):
           dib.rectangle([(offx + (i//2 - 1) * px(i), y + j * px(i)), (offx + (i//2) * px(i) - 1, y + (j + 1) * px(i) - 1)], par(j, cnp))
       if cnp:
           cnp = False
       else:
           cnp = True

img.save("output.png")
            

