class Polygon {
    constructor(a) {
        this.sides = [];
        this.sides = a;
    }
    perimeter() {
        let p = 0;
        for (var i = 0; i < this.sides.length; i++) {
            p += this.sides[i];
        }
        return p;
    }
}
