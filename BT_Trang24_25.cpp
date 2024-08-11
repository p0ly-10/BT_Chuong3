#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Hàm đếm số khoảng trắng trong chuỗi
int demKhoangTrang(const char* str) {
    int count = 0;
    while (*str) {
        if (isspace(*str)) count++;
        str++;
    }
    return count;
}

// Hàm xóa khoảng trắng thừa trong chuỗi
void xoaKhoangTrangThua(char* str) {
    int i, x = 0;
    int len = strlen(str);
    for (i = 0; i < len; i++) {
        if (!isspace(str[i]) || (i > 0 && !isspace(str[i - 1]))) {
            str[x++] = str[i];
        }
    }
    if (x > 0 && isspace(str[x - 1])) x--;
    str[x] = '\0';
}

// Hàm đổi kí tự đầu của mỗi từ thành chữ in hoa và các kí tự còn lại thành chữ thường
void chuanHoaChuoi(char* str) {
    int i;
    int len = strlen(str);
    int newWord = 1;
    for (i = 0; i < len; i++) {
        if (isspace(str[i])) {
            newWord = 1;
        }
        else {
            if (newWord) {
                str[i] = toupper(str[i]);
                newWord = 0;
            }
            else {
                str[i] = tolower(str[i]);
            }
        }
    }
}

// Hàm tìm kiếm tên trong chuỗi họ tên
void timKiemTen(const char* hoTen, const char* ten) {
    const char* lastSpace = strrchr(hoTen, ' ');
    if (lastSpace && strcmp(lastSpace + 1, ten) == 0) {
        printf("Ten nay da nhap dung.\n");
    }
    else {
        printf("Ten nay da nhap sai.\n");
    }
}

// Hàm cắt chuỗi họ tên thành họ lót và tên
void catHoTen(const char* hoTen, char* hoLot, char* ten) {
    const char* lastSpace = strrchr(hoTen, ' ');
    if (lastSpace) {
        strncpy(hoLot, hoTen, lastSpace - hoTen);
        hoLot[lastSpace - hoTen] = '\0';
        strcpy(ten, lastSpace + 1);
    }
    else {
        strcpy(hoLot, "");
        strcpy(ten, hoTen);
    }
}

// Hàm chèn từ vào vị trí bất kỳ trong chuỗi
void chenTu(char* str, const char* tu, int viTri) {
    int len = strlen(str);
    int tuLen = strlen(tu);
    if (viTri > len) viTri = len;
    memmove(str + viTri + tuLen, str + viTri, len - viTri + 1);
    memcpy(str + viTri, tu, tuLen);
}

// Hàm xóa từ trong chuỗi
void xoaTu(char* str, const char* tu) {
    char* pos = strstr(str, tu);
    if (pos) {
        int len = strlen(tu);
        memmove(pos, pos + len, strlen(pos + len) + 1);
    }
}

// Hàm đếm tần suất xuất hiện của mỗi ký tự trong chuỗi
void demTanSuat(const char* str) {
    int freq[256] = { 0 };
    while (*str) {
        freq[(unsigned char)*str]++;
        str++;
    }
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            printf("Ky tu %c xuat hien %d lan.\n", i, freq[i]);
        }
    }
}

// Hàm tìm ký tự xuất hiện nhiều nhất trong chuỗi
char timKyTuXuatHienNhieuNhat(const char* str) {
    int freq[256] = { 0 };
    while (*str) {
        freq[(unsigned char)*str]++;
        str++;
    }
    int maxFreq = 0;
    char maxChar = '\0';
    for (int i = 0; i < 256; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            maxChar = i;
        }
    }
    return maxChar;
}

int main() {
    char str[100], ten[30], hoLot[100], tenTimKiem[30];

    printf("Nhap chuoi: ");
    scanf("%s", &str);

    // 1. Đếm số khoảng trắng
    printf("So khoang trang: %d\n", demKhoangTrang(str));

    // 2. Xóa khoảng trắng thừa
    xoaKhoangTrangThua(str);
    printf("Chuoi sau khi xoa khoang trang thua: %s\n", str);

    // 3. Chuan hoa chuoi
    chuanHoaChuoi(str);
    printf("Chuoi sau khi chuan hoa: %s\n", str);

    // 4. Tìm kiếm tên
    printf("Nhap ten can tim: ");
    scanf("%s", tenTimKiem);
    timKiemTen(str, tenTimKiem);

    // 5. Cắt họ tên
    catHoTen(str, hoLot, ten);
    printf("Ho lot: %s, Ten: %s\n", hoLot, ten);

    // 6. Chèn từ vào vị trí bất kỳ
    char tuChen[30];
    int viTriChen;
    printf("Nhap tu can chen: ");
    scanf("%s", tuChen);
    printf("Nhap vi tri can chen: ");
    scanf("%d", &viTriChen);
    getchar(); // Đọc ký tự xuống dòng
    chenTu(str, tuChen, viTriChen);
    printf("Chuoi sau khi chen tu: %s\n", str);

    // 7. Xóa từ trong chuỗi
    char tuXoa[30];
    printf("Nhap tu can xoa: ");
    scanf("%s", tuXoa);
    xoaTu(str, tuXoa);
    printf("Chuoi sau khi xoa tu: %s\n", str);

    // 8. Đếm tần suất xuất hiện của mỗi ký tự
    printf("Tan suat xuat hien cua moi ky tu:\n");
    demTanSuat(str);

    // 9. Tìm ký tự xuất hiện nhiều nhất
    char kyTuNhieuNhat = timKyTuXuatHienNhieuNhat(str);
    printf("Ky tu xuat hien nhieu nhat: %c\n", kyTuNhieuNhat);

    return 0;
}
