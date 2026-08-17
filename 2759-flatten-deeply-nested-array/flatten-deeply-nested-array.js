var flat = function (arr, n) {
    function flatten(array, depth) {
        const result = [];

        for (const item of array) {
            if (Array.isArray(item) && depth < n) {
                result.push(...flatten(item, depth + 1));
            } else {
                result.push(item);
            }
        }

        return result;
    }

    return flatten(arr, 0);
};