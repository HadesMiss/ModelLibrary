(self.webpackChunkmodel_library_ts=self.webpackChunkmodel_library_ts||[]).push([[4748],{44748:function(e,t,n){e=n.nmd(e),ace.define("ace/mode/lua_highlight_rules",["require","exports","module","ace/lib/oop","ace/mode/text_highlight_rules"],(function(e,t,n){"use strict";var r=e("../lib/oop"),i=e("./text_highlight_rules").TextHighlightRules,o=function(){var e=this.createKeywordMapper({keyword:"break|do|else|elseif|end|for|function|if|in|local|repeat|return|then|until|while|or|and|not","support.function":"string|xpcall|package|tostring|print|os|unpack|require|getfenv|setmetatable|next|assert|tonumber|io|rawequal|collectgarbage|getmetatable|module|rawset|math|debug|pcall|table|newproxy|type|coroutine|_G|select|gcinfo|pairs|rawget|loadstring|ipairs|_VERSION|dofile|setfenv|load|error|loadfile|sub|upper|len|gfind|rep|find|match|char|dump|gmatch|reverse|byte|format|gsub|lower|preload|loadlib|loaded|loaders|cpath|config|path|seeall|exit|setlocale|date|getenv|difftime|remove|time|clock|tmpname|rename|execute|lines|write|close|flush|open|output|type|read|stderr|stdin|input|stdout|popen|tmpfile|log|max|acos|huge|ldexp|pi|cos|tanh|pow|deg|tan|cosh|sinh|random|randomseed|frexp|ceil|floor|rad|abs|sqrt|modf|asin|min|mod|fmod|log10|atan2|exp|sin|atan|getupvalue|debug|sethook|getmetatable|gethook|setmetatable|setlocal|traceback|setfenv|getinfo|setupvalue|getlocal|getregistry|getfenv|setn|insert|getn|foreachi|maxn|foreach|concat|sort|remove|resume|yield|status|wrap|create|running|__add|__sub|__mod|__unm|__concat|__lt|__index|__call|__gc|__metatable|__mul|__div|__pow|__len|__eq|__le|__newindex|__tostring|__mode|__tonumber","keyword.deprecated":"setn|foreach|foreachi|gcinfo|log10|maxn","constant.library":"string|package|os|io|math|debug|table|coroutine","constant.language":"true|false|nil|_G|_VERSION","variable.language":"self"},"identifier"),t="(?:\\d+)",n="(?:"+("(?:(?:"+t+"?(?:\\.\\d+))|(?:"+t+"\\.))")+")";this.$rules={start:[{stateName:"bracketedComment",onMatch:function(e,t,n){return n.unshift(this.next,e.length-2,t),"comment"},regex:/\-\-\[=*\[/,next:[{onMatch:function(e,t,n){return e.length==n[1]?(n.shift(),n.shift(),this.next=n.shift()):this.next="","comment"},regex:/\]=*\]/,next:"start"},{defaultToken:"comment"}]},{token:"comment",regex:"\\-\\-.*$"},{stateName:"bracketedString",onMatch:function(e,t,n){return n.unshift(this.next,e.length,t),"string.start"},regex:/\[=*\[/,next:[{onMatch:function(e,t,n){return e.length==n[1]?(n.shift(),n.shift(),this.next=n.shift()):this.next="","string.end"},regex:/\]=*\]/,next:"start"},{defaultToken:"string"}]},{token:"string",regex:'"(?:[^\\\\]|\\\\.)*?"'},{token:"string",regex:"'(?:[^\\\\]|\\\\.)*?'"},{token:"constant.numeric",regex:n},{token:"constant.numeric",regex:"(?:(?:(?:[1-9]\\d*)|(?:0))|(?:0[xX][\\dA-Fa-f]+))\\b"},{token:e,regex:"[a-zA-Z_$][a-zA-Z0-9_$]*\\b"},{token:"keyword.operator",regex:"\\+|\\-|\\*|\\/|%|\\#|\\^|~|<|>|<=|=>|==|~=|=|\\:|\\.\\.\\.|\\.\\."},{token:"paren.lparen",regex:"[\\[\\(\\{]"},{token:"paren.rparen",regex:"[\\]\\)\\}]"},{token:"text",regex:"\\s+|\\w+"}]},this.normalizeRules()};r.inherits(o,i),t.LuaHighlightRules=o})),ace.define("ace/mode/folding/lua",["require","exports","module","ace/lib/oop","ace/mode/folding/fold_mode","ace/range","ace/token_iterator"],(function(e,t,n){"use strict";var r=e("../../lib/oop"),i=e("./fold_mode").FoldMode,o=e("../../range").Range,a=e("../../token_iterator").TokenIterator,l=t.FoldMode=function(){};r.inherits(l,i),function(){this.foldingStartMarker=/\b(function|then|do|repeat)\b|{\s*$|(\[=*\[)/,this.foldingStopMarker=/\bend\b|^\s*}|\]=*\]/,this.getFoldWidget=function(e,t,n){var r=e.getLine(n),i=this.foldingStartMarker.test(r),o=this.foldingStopMarker.test(r);if(i&&!o){var a;if("then"==(a=r.match(this.foldingStartMarker))[1]&&/\belseif\b/.test(r))return;if(a[1]){if("keyword"===e.getTokenAt(n,a.index+1).type)return"start"}else{if(!a[2])return"start";if("bracketedComment"==(l=e.bgTokenizer.getState(n)||"")[0]||"bracketedString"==l[0])return"start"}}if("markbeginend"!=t||!o||i&&o)return"";if("end"===(a=r.match(this.foldingStopMarker))[0]){if("keyword"===e.getTokenAt(n,a.index+1).type)return"end"}else{if("]"!==a[0][0])return"end";var l;if("bracketedComment"==(l=e.bgTokenizer.getState(n-1)||"")[0]||"bracketedString"==l[0])return"end"}},this.getFoldWidgetRange=function(e,t,n){var r,i=e.doc.getLine(n);return(r=this.foldingStartMarker.exec(i))?r[1]?this.luaBlock(e,n,r.index+1):r[2]?e.getCommentFoldRange(n,r.index+1):this.openingBracketBlock(e,"{",n,r.index):(r=this.foldingStopMarker.exec(i))?"end"===r[0]&&"keyword"===e.getTokenAt(n,r.index+1).type?this.luaBlock(e,n,r.index+1):"]"===r[0][0]?e.getCommentFoldRange(n,r.index+1):this.closingBracketBlock(e,"}",n,r.index+r[0].length):void 0},this.luaBlock=function(e,t,n,r){var i=new a(e,t,n),l={function:1,do:1,then:1,elseif:-1,end:-1,repeat:1,until:-1},s=i.getCurrentToken();if(s&&"keyword"==s.type){var u=s.value,g=[u],d=l[u];if(d){var c=-1===d?i.getCurrentTokenColumn():e.getLine(t).length,h=t;for(i.step=-1===d?i.stepBackward:i.stepForward;s=i.step();)if("keyword"===s.type){var f=d*l[s.value];if(f>0)g.unshift(s.value);else if(f<=0){if(g.shift(),!g.length&&"elseif"!=s.value)break;0===f&&g.unshift(s.value)}}if(!s)return null;if(r)return i.getCurrentTokenRange();t=i.getCurrentTokenRow();return-1===d?new o(t,e.getLine(t).length,h,c):new o(h,c,t,i.getCurrentTokenColumn())}}}}.call(l.prototype)})),ace.define("ace/mode/lua",["require","exports","module","ace/lib/oop","ace/mode/text","ace/mode/lua_highlight_rules","ace/mode/folding/lua","ace/range","ace/worker/worker_client"],(function(e,t,n){"use strict";var r=e("../lib/oop"),i=e("./text").Mode,o=e("./lua_highlight_rules").LuaHighlightRules,a=e("./folding/lua").FoldMode,l=e("../range").Range,s=e("../worker/worker_client").WorkerClient,u=function(){this.HighlightRules=o,this.foldingRules=new a,this.$behaviour=this.$defaultBehaviour};r.inherits(u,i),function(){this.lineCommentStart="--",this.blockComment={start:"--[[",end:"--]]"};var e={function:1,then:1,do:1,else:1,elseif:1,repeat:1,end:-1,until:-1},t=["else","elseif","end","until"];this.getNextLineIndent=function(t,n,r){var i=this.$getIndent(n),o=0,a=this.getTokenizer().getLineTokens(n,t).tokens;return"start"==t&&(o=function(t){for(var n=0,r=0;r<t.length;r++){var i=t[r];"keyword"==i.type?i.value in e&&(n+=e[i.value]):"paren.lparen"==i.type?n+=i.value.length:"paren.rparen"==i.type&&(n-=i.value.length)}return n<0?-1:n>0?1:0}(a)),o>0?i+r:o<0&&i.substr(i.length-r.length)==r&&!this.checkOutdent(t,n,"\n")?i.substr(0,i.length-r.length):i},this.checkOutdent=function(e,n,r){if("\n"!=r&&"\r"!=r&&"\r\n"!=r)return!1;if(n.match(/^\s*[\)\}\]]$/))return!0;var i=this.getTokenizer().getLineTokens(n.trim(),e).tokens;return!(!i||!i.length)&&("keyword"==i[0].type&&-1!=t.indexOf(i[0].value))},this.getMatching=function(t,n,r){if(void 0==n){var i=t.selection.lead;r=i.column,n=i.row}var o=t.getTokenAt(n,r);if(o&&o.value in e)return this.foldingRules.luaBlock(t,n,r,!0)},this.autoOutdent=function(e,t,n){var r=t.getLine(n).match(/^\s*/)[0].length;if(r&&n){var i=this.getMatching(t,n,r+1);if(i&&i.start.row!=n){var o=this.$getIndent(t.getLine(i.start.row));o.length!=r&&(t.replace(new l(n,0,n,r),o),t.outdentRows(new l(n+1,0,n+1,0)))}}},this.createWorker=function(e){var t=new s(["ace"],"ace/mode/lua_worker","Worker");return t.attachToDocument(e.getDocument()),t.on("annotate",(function(t){e.setAnnotations(t.data)})),t.on("terminate",(function(){e.clearAnnotations()})),t},this.$id="ace/mode/lua",this.snippetFileId="ace/snippets/lua"}.call(u.prototype),t.Mode=u})),ace.require(["ace/mode/lua"],(function(t){e&&(e.exports=t)}))}}]);