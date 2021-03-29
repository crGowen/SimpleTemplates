// shorthand js function declarations

const short = {
    h: document.head,

    b: document.body,

    create: (type, id, classes) => {
        var c = document.createElement(type);
        if (id.length > 0) {
            c.id = id;
        }
        for (var i = 0; i < classes.length; i++) {
            c.classList.add(classes[i]);
        }
        return c;
    },

    byId: (name) => { return document.getElementById(name); },

    byClass: (clname) => { return document.getElementsByClassName(clname); },

    del: (elem) => { if (elem)
        elem.parentNode.removeChild(elem); },

    clearChildren: (elem) => {
        while (elem.childNodes.length > 0) {
            elem.removeChild(elem.childNodes[0]);
        }
    },

    checkForMobile: () => {
        var regex = /Mobi|Android/i;
        return regex.test(navigator.userAgent);
    },

    generator: (appendTo, html, args) => {
        var htmlRes = ``;
        for (var arg of args) {
            htmlRes = html;
            for (var key in arg) {
                htmlRes = htmlRes.replaceAll(`[>>${key}<<]`, arg[key]);
            }
            appendTo.innerHTML += htmlRes;
        }
    },

    fillWithHtml: async (appendTo, fetchUrl) => {

        let response = await fetch(fetchUrl);
        let result = await response.text();
        let parser = new DOMParser();
        let dom = parser.parseFromString(result, "text/html");

        appendTo.innerHTML += dom.getElementsByTagName("body")[0].innerHTML;
    }
};
