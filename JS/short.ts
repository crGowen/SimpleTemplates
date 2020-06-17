// shorthand js function declarations

var short = {
    h: document.head,

    b: document.body,

    create: function(type:string, id:string, classes:string[]) {
        let c = document.createElement(type);

        if (id.length > 0) {
            c.id = id;
        }

        for (let i = 0; i < classes.length; i++) {
            c.classList.add(classes[i]);
        }

        return c;
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
