from jutge import read
from PIL import Image, ImageDraw

f, n, a, r1, g1, b1, r2, g2, b2 = read(str, int, int, int, int, int, int, int, int)

d = n * a

img = Image.new("RGB", (d, d), f)
dib = ImageDraw.Draw(img)

for i in range(n):
    if n % 2 != 0 and i == n//2:
        dib.rectangle([(i * a, i * a), (i * a + a - 1, i * a + a - 1)], ((r1 + r2)//2, (g1 + g2)//2, (b1 + b2)//2))
    else:
        dib.rectangle([(i * a, i * a), (i * a + a - 1, i * a + a - 1)], (r1, g1, b1))
        dib.rectangle([((n - i - 1) * a, i * a), ((n - i - 1) * a + a - 1, i * a + a - 1)], (r2, g2, b2))
img.save("output.png")
