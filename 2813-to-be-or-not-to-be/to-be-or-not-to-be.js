/**
 * @param {string} val
 * @return {Object}
 */
var expect = (val) => {
    return {
        toBe : (other) => {
            if(val === other) return true;
            throw new Error("Not Equal");
        },
        notToBe : (other) => {
            if(val !== other) return true;
            throw new Error("Equal");
        }
    }
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */