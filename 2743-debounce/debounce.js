var debounce = function(fn, t) {
    let timer;

    return function(...args) {
        // Cancel the previous scheduled call
        clearTimeout(timer);

        // Schedule a new call
        timer = setTimeout(() => {
            fn(...args);
        }, t);
    };
};