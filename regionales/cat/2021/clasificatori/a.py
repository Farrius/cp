from jutge import read
from PIL import Image, ImageDraw

n, p = read(int, int)

i1 = n - 1
j1 = n - 1
i4 = 0
j4 = 0

img = Image.new("RGB", (n, n), "Red")
dib = ImageDraw.Draw(img)

for i in range(p):
    y = int(input())
    x = int(input())
    dib.point([(y, x)], "Black");
    if (y < i1):
        i1 = y
    if (x < j1):
        j1 = x
    if (y > i4):
        i4 = y
    if (x > j4):
        j4 = x;


if i1 > 0:
    dib.rectangle([(0, 0), (i1 - 1, n - 1)], "Beige")
if j1 > 0:
    dib.rectangle([(0, 0), (n - 1, j1 - 1)], "Beige")
if i4 < n - 1:
    dib.rectangle([(i4 + 1, j1), (n - 1, n - 1)], "Beige")
if j4 < n - 1:
    dib.rectangle([(i1, j4 + 1), (n - 1, n - 1)], "Beige")

img.save("output.png")


