#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define WIDTH 101
#define HEIGHT 103
#define SIZE 501

typedef struct {
    int px, py, vx, vy;
} Cord;

Cord data[SIZE];
// code to write a BMP image from chatGPT
#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;      // File type ('BM')
    uint32_t bfSize;      // Size of the file
    uint16_t bfReserved1; // Reserved (0)
    uint16_t bfReserved2; // Reserved (0)
    uint32_t bfOffBits;   // Offset to pixel data
} BMPFileHeader;

typedef struct {
    uint32_t biSize;          // Size of the header
    int32_t biWidth;          // Width of the image
    int32_t biHeight;         // Height of the image (negative for top-down)
    uint16_t biPlanes;        // Number of color planes (1)
    uint16_t biBitCount;      // Bits per pixel (24 for RGB)
    uint32_t biCompression;   // Compression type (0 = none)
    uint32_t biSizeImage;     // Image data size (can be 0 for uncompressed images)
    int32_t biXPelsPerMeter;  // Horizontal resolution (pixels per meter)
    int32_t biYPelsPerMeter;  // Vertical resolution (pixels per meter)
    uint32_t biClrUsed;       // Number of colors used
    uint32_t biClrImportant;  // Important colors (0 = all)
} BMPInfoHeader;
#pragma pack(pop)

void writeBMP(const char *filename, uint32_t pixels[HEIGHT][WIDTH]) {
    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;

    // Calculate padding for BMP rows (4-byte alignment)
    int rowPadding = (4 - (WIDTH * 3) % 4) % 4;

    // File header
    fileHeader.bfType = 0x4D42; // 'BM'
    fileHeader.bfOffBits = sizeof(BMPFileHeader) + sizeof(BMPInfoHeader);
    fileHeader.bfSize = fileHeader.bfOffBits + (WIDTH * 3 + rowPadding) * HEIGHT;
    fileHeader.bfReserved1 = 0;
    fileHeader.bfReserved2 = 0;

    // Info header
    memset(&infoHeader, 0, sizeof(infoHeader));
    infoHeader.biSize = sizeof(BMPInfoHeader);
    infoHeader.biWidth = WIDTH;
    infoHeader.biHeight = -HEIGHT; // Top-down BMP
    infoHeader.biPlanes = 1;
    infoHeader.biBitCount = 24;
    infoHeader.biCompression = 0;
    infoHeader.biSizeImage = (WIDTH * 3 + rowPadding) * HEIGHT;
    infoHeader.biXPelsPerMeter = 2835; // Approx 72 DPI
    infoHeader.biYPelsPerMeter = 2835;

    // Write BMP file
    FILE *f = fopen(filename, "wb");
    if (!f) {
        perror("Error opening file");
        return;
    }

    fwrite(&fileHeader, sizeof(fileHeader), 1, f);
    fwrite(&infoHeader, sizeof(infoHeader), 1, f);

    // Write pixel data (row by row, with padding)
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            uint32_t pixel = pixels[i][j];
            uint8_t rgb[3] = {
                (pixel >> 0) & 0xFF, // Blue
                (pixel >> 8) & 0xFF, // Green
                (pixel >> 16) & 0xFF // Red
            };
            fwrite(rgb, sizeof(rgb), 1, f);
        }
        // Add row padding
        uint8_t padding[3] = {0, 0, 0};
        fwrite(padding, rowPadding, 1, f);
    }

    fclose(f);
}



void solve() {
    int px, py, vx, vy;
    int i = 0;

    while (scanf("p=%d,%d v=%d,%d\n", &px, &py, &vx, &vy) != EOF) {
        data[i++] = (Cord){.px = px, .py = py, .vx = vx, .vy = vy};
    }

    uint32_t pixels[HEIGHT][WIDTH] = {0};

    for (int time = 7000; time < 7201; time++) {
        char file_name[50];
        sprintf(file_name, "images/image%d.bmp", time);
        memset(pixels, 0, sizeof(pixels));
        for (int i = 0; i < SIZE; i++) {
            int px = (data[i].px + ((data[i].vx * time) % WIDTH + WIDTH) % WIDTH) % WIDTH;
            int py = (data[i].py + ((data[i].vy * time) % HEIGHT + HEIGHT) % HEIGHT) % HEIGHT;
            pixels[py][px] = 0xFF0000;
        }
        writeBMP(file_name, pixels);
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    solve();
    return 0;
}
