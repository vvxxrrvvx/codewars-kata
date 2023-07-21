class Datamining:

    def __init__(self, train_set):
        self.x_train = [point[0] for point in train_set]
        self.y_train = [point[1] for point in train_set]
        self.slope, self.intercept = self.linear_regression()

    def linear_regression(self):
        n = len(self.x_train)
        sum_x = sum(self.x_train)
        sum_y = sum(self.y_train)
        sum_xy = sum(x * y for x, y in zip(self.x_train, self.y_train))
        sum_x_squared = sum(x ** 2 for x in self.x_train)

        slope = (n * sum_xy - sum_x * sum_y) / (n * sum_x_squared - sum_x ** 2)
        intercept = (sum_y - slope * sum_x) / n

        return slope, intercept

    def predict(self, x):
        return self.slope * x + self.intercept