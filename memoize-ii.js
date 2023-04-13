class Trie{
    constructor() {
        this.hasVal = false;
        this.val = undefined;
        this.child = new Map();
    }
}
function memoize(fn) {
    let mem = new Trie();
    return (...args) => {
        let current = mem, next;
        for (arg of args) {
            if (!(next = current.child.get(arg)))
                current.child.set(arg, (next = new Trie()));
            current = next;
        }
        if (!current.hasVal) {
            current.hasVal = true;
            current.val = fn(...args);
        }
        return current.val;
    }
}