int binsearch(int x, const int v[], int n) {
    int low = 0, high = n - 1;
    int mid = low + (high - low) / 2;
    while (low <= high && x != v[mid]) {
        if (x < v[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        mid = low + (high - low) / 2;
    }
    if (x == v[mid]) {
        return mid;
    } else {
        return -1;
    }
}

int main() {

}