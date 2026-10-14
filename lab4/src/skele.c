int **makeIntArray2D(int width, int height) {
  int **arr = safeMalloc(height * sizeof(int *));
  arr[0] = safeMalloc(width * height * sizeof(int));
  for (int row = 1; row < height; row++) {
    arr[row] = arr[row - 1] + width;
  }
  return arr;
}

void destroyIntArray2D(int **arr) {
  free(arr[0]);
  free(arr);
}