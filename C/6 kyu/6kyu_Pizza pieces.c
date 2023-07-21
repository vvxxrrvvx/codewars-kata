int max_pizza(int cuts) {
    return cuts >= 0 ? (cuts * (cuts + 1) / 2) + 1 : -1;
}