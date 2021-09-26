from jutge import read
from PIL import Image, ImageDraw

n, s = read(int, int)

x = 0
y = 0

img = Image.new("RGB", (n * s * (n + 1)//2, n * s * (n + 1)//2), "Blue")
dib = ImageDraw.Draw(img)

def px (k):
    return k * s

cni = False
cnp = False

def inp (cn):
    global cni
    if cn:
        if cni:
          cni = False
        else:
          cni = True
        return "Yellow"
    else:
        if cni:
          cni = False
        else:
          cni = True
        return "Red"

def par (cn):
    global cnp
    if cn:
        if cnp:
          cnp = False
        else:
          cnp = True
        return "Lime"
    else:
        if cnp:
          cnp = False
        else:
          cnp = True
        return "Blue"

        
for i in range(n, 0, -1):
    if i % 2 == 1:
       cni = True
       for j in range(i//2 + 1):
           dib.rectangle([(j * px(i), y), ( j * px(i) + px(i) - 1), y + px(i) - 1], inp(cni))
       y += px(i);
       for j in range(i//2):
           dib.rectangle([((i//2) * px(i), y + j * px(i)), ((i//2 + 1) * px(i) - 1), y + (j + 1) * px(i) - 1], inp(cni))
    else:
       cnp = True
       offx = px(i)/2
       for j in range(i//2):
           dib.rectangle([(offx + j * px(i), y) , (offx + j * px(i) + px(i) - 1, y + px(i) - 1)], par(cnp))
       y += px(i);
       for j in range(i//2 - 1):
           dib.rectangle([(offx + (i//2 - 1) * px(i), y + j * px(i)), (offx + (i//2) * px(i) - 1, y + (j + 1) * px(i) - 1)], par(cnp))

img.save("output.png")
            

