var cancellable = function (generator) {
    let cancelled = false;
    let finished = false;

    let resolvePromise;
    let rejectPromise;

    const promise = new Promise((resolve, reject) => {
        resolvePromise = resolve;
        rejectPromise = reject;
    });

    function run(method, value) {
        if (finished) return;

        let result;

        try {
            result = generator[method](value);
        } catch (error) {
            finished = true;
            rejectPromise(error);
            return;
        }

        if (result.done) {
            finished = true;
            resolvePromise(result.value);
            return;
        }

        Promise.resolve(result.value)
            .then(
                value => {
                    if (cancelled) return;
                    run("next", value);
                },
                error => {
                    if (cancelled) return;
                    run("throw", error);
                }
            );
    }

    const cancel = () => {
        if (finished) return;

        cancelled = true;

        try {
            const result = generator.throw("Cancelled");

            if (result.done) {
                finished = true;
                resolvePromise(result.value);
            } else {
                
                cancelled = false;

                Promise.resolve(result.value).then(
                    value => run("next", value),
                    error => run("throw", error)
                );
            }
        } catch (error) {
            finished = true;
            rejectPromise(error);
        }
    };

    
    run("next");

    return [cancel, promise];
};