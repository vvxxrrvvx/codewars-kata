class Vector {
  constructor(components) {
    this.components = components;
  }
  get length() {
    return this.components.length;
  }
  add(vector) {
    const func = (component, i) => component + vector.components[i];
    const components = this.mapComponents(vector, func);
    return new Vector(components);
  }
  subtract(vector) {
    const func = (component, i) => component - vector.components[i];
    const components = this.mapComponents(vector, func);
    return new Vector(components);
  }
  dot(vector) {
    const func = (component, i) => component * vector.components[i];
    const components = this.mapComponents(vector, func);
    return components.reduce((sum, component) => sum + component);
  }
  norm() {
    return Math.sqrt(this.components.reduce((sum, component) => {
      return sum + component * component;
    }, 0));
  }
  equals(vector) {
    return this.components.every((component, i) => component === vector.components[i]);
  }
  mapComponents(vector, func) {
    if (vector.length != this.length)
      throw new Error('Vectors must be the same length');
    const components = this
      .components
      .map(func);
    return components;
  }
  toString() {
    return `(${this.components})`;
  }
}