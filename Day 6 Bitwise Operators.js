
function getMaxLessThanK(a, b) {
    var m = 0;
    for (var i = 1; i < a; i++) {
        for (var j = i + 1; j <= a; j++) {
            var t = i & j;
            if (t > m && t < b) {
                m = t;
            }
        }
    }
    return m;
}
