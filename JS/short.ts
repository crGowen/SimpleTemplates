// shorthand js function declarations

var short = {
    h: document.head,

    b: document.body,

    create: function(...args:string[]) {
        if (args.length == 1) {
            return document.createElement(args[0]);
        } else if (args.length > 1) {
            let c = document.createElement(args[0]);
            c.id = args[1];
            return c;
        }
    },

    byId: function(name:string) {return document.getElementById(name); },

    byClass: function(clname:string) {return document.getElementsByClassName(clname); },

    del: function(elem:Element) {if (elem) elem.parentNode.removeChild(elem); },

    clearChildren: function(elem:Element) {
        while (elem.childNodes.length > 0) {
            elem.removeChild(elem.childNodes[0]);
        }
    }
}