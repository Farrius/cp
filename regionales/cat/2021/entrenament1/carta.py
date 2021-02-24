from jutge import read
from PIL import Image, ImageDraw

f, t, n, m = read(str, str, int, int)

img = Image.new("RGB", (n, m), f)
dib = ImageDraw.Draw(img);

dib.polygon([(0, 0), (n - 1, 0), (n/2, n/2)], t)

img.save("output.png")
