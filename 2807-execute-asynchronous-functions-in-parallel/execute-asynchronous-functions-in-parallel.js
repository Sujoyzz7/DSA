/**
 * @param {Function[]} functions
 * @return {Promise<any[]>}
 */
var promiseAll = function(functions) {
    return new Promise((resolve, reject) => {
        const n = functions.length;
        const result = new Array(n);
        let completed = 0;

        functions.forEach((fn, index) => {
            fn()
                .then(value => {
                    result[index] = value;
                    completed++;

                    if (completed === n) {
                        resolve(result);
                    }
                })
                .catch(error => {
                    reject(error);
                });
        });
    });
};