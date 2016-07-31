// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

$(function(){
    var page = window.location.pathname.split("/").pop().split("#")[0];

    $("li > a[href='index.html'] > span")
        .before("<i class='octicon octicon-book'></i> ");
    $("li > a[href='files.html'] > span")
        .before("<i class='octicon octicon-file-code'></i> ");
    $("li > a[href='modules.html'] > span")
        .before("<i class='octicon octicon-code'></i> ");
    $("li > a[href='namespacemembers.html'] > span")
        .before("<i class='octicon octicon-list-unordered'></i> ");

    $(".current").removeClass("current").addClass("active");

    $("[id^='navrow']").each(function(){
        if($("ul > li", this).length > 4)
            $(this).addClass("hidden-xs");
    });

    $("[id^='navrow']:has(a[href^='namespacemembers']):has(a[href^='namespacemembers_type'])")
        .remove();

    $("ul > li > a[href^='#index_']").click(function(){
        $(this).parent().addClass("active").siblings().removeClass("active");
    }).parent().removeClass("active");

    $("h3:has(a[id^='index_']) + ul > li")
        .each(function(){
            var text = $(this).text().match(/^([_a-zA-Z0-9]+)/g);
            $(this).html($("> a", this).html(text));
        })
        .parent()
        .addClass("list-inline index-entry");

    $("[id^='navrow'] > ul, #nav-path > ul")
        .addClass("nav nav-pills nav-justified")
        .find("a.el").removeClass("el");

    $("div.toc").addClass("panel pull-right");

    $("div.toc > ul").addClass("panel-body");
    $("div.toc h3")
        .addClass("panel-title text-center")
        .wrap("<div class='panel-heading'>");

    $("div.header")
        .each(function(){
            $("> div.headertitle > div.title", this)
                .wrapInner("<h1>")
                .contents()
                .prependTo($("+ div.contents", this));
        })
        .remove();

    $("div.contents").addClass("col-xs-12");

    $("h1").addClass("page-header");

    $("div.qindex + table td > a[href^='namespace']")
        .each(function(){
            var $parent = $(this).parent();
            $(this).remove();
            $parent.html($parent.html().split("()").join(''));
        });

    $("div.memitem > div.memproto")
        .removeClass("memproto")
        .addClass("panel-heading")
        .attr("data-toggle", "collapse-next")
        .attr("role", "button")
        .each(function(){
            $("<div class='panel-title'>")
                .append($(".memtemplate", this).append("<br>").contents())
                .append($(".memname td", this).contents())
                .prependTo(this)
                .contents()
                .each(function(){
                    if(this.nodeType == 3){
                        this.data = this.data
                            .replace(
                                /= typedef( typename)? (?!std::).+/g,
                                "= unspecified"
                            )
                            .replace(/= typedef/g, "=")
                            .replace(/detail::[_a-zA-Z_]+/g, "unspecified");
                    }
                });

            $(".memtemplate", this).remove();
            $(".memname", this).remove();
        });

    $("div.memitem > div.memdoc")
        .addClass("panel-body")
        .wrap("<div class='panel-collapse collapse'>");

    $("div.memitem").addClass("panel panel-default");

    $("table.memberdecls td.memItemLeft, table.memberdecls td.memTemplItemLeft")
        .each(function(){
            $("+ td", this).contents().appendTo(this);
            $("+ td", this).remove();
        })
        .removeAttr("valign")
        .removeAttr("align");

    $("table.memberdecls td.memTemplParams")
        .each(function(){
            $(this).append("<br>").contents()
                .prependTo($("+ tr td", $(this).parent("tr")));
            $(this).parent("tr").remove();
        })

    $("a > span.icondoc")
        .removeClass("icondoc")
        .addClass("octicon octicon-file-code")
        .each(function(){
            $("+", $(this).parent()).appendTo($(this).parent());
        });

    $("span.iconfopen")
        .removeClass("iconfopen")
        .addClass("octicon octicon-file-directory");

    $("span.iconfclosed")
        .removeClass("iconfclosed")
        .addClass("octicon octicon-file-directory")

    $("table.memberdecls td.memItemLeft")
        .each(function(){
            if($(this).text().match(/^directory/)){
                $(this).html($(this).html().split("directory").join(""));
                $(this).prepend("<span class='octicon octicon-file-directory'>");
            }
            if($(this).text().match(/^file/)){
                $(this).html($(this).html().split("file").join(""));
                $(this).prepend("<span class='octicon octicon-file-code'>");
            }
        });

    $("table.memberdecls td.memItemLeft > b + a:contains([code])")
        .each(function(){
            $(this).html($(this).prev().text());
            $(this).prev().remove();
        });

    $("span.octicon-file-directory, span.octicon-file-code")
        .each(function(){
            $("+ a", this).addClass("el").prepend(this);
        });

    $("table.memberdecls").addClass("table table-striped");
    $("table.params").addClass("table");
    $("table.directory").addClass("table table-striped");
    $("table.doxtable")
        .addClass("table table-bordered")
        .wrap("<div class='table-responsive'>");
    $("table.doxtable p.starttd").replaceWith(function(){
        return $(this).html();
    });
    $("table.doxtable p.endtd").replaceWith(function(){
        return $(this).html();
    });


    $("dl.section.see").replaceWith(function(){
        return $(this).find("dd").contents();
    });

    $(".ttc").remove();
    $("div.fragment div.line span.lineno").remove();
    $("div.fragment")
        .each(function(){
            $(this)
                .contents()
                .slice($(this).contents().index($("div.line:last-child", this)) + 1)
                .remove();
        });

    $("div.fragment")
        .replaceWith(function(){
            return $("<pre class='fragment'>").append($(this).contents());
        });

    $("span.comment").addClass("text-muted");
    $("code a").removeClass("el");
    $("a.el")
        .contents()
        .each(function(){
            if(this.nodeType == 3)
                this.data = this.data.replace(/metal::/g, "");
        });
    $("a.el").wrapInner("<strong>");
    $("a.download").attr("href", $("a#download").attr("href"));
    $("a.anchor").each(function(){
        $(this).attr("href", "#" + $(this).attr("id"));
    });
    $("a[href^='" + page + "#'], a[href^=#]")
        .click(function(){
            var href = "#" + $.attr(this, "href").split("#").pop();
            $("html, body").animate({
                scrollTop: $(href).offset().top
            }, 300, function(){
                window.location.hash = href;
            });

            return false;
        });

    $(".levels").remove();
    $(".summary").remove();
    $(".desc").remove();
    $(".qindex").remove();
    $(".arrow").remove();

    $(".groupheader").remove();
    $(".ingroups").remove();
    $(".heading").remove();
    $(".memSeparator").remove();
    $("[class^='separator\\:']").remove();

    $(".el").removeClass("el")
    $(".code").removeClass("code");
    $(".comment").removeClass("comment");
    $(".contents").removeClass("contents");
    $(".params").removeClass("params");
    $(".navpath").removeClass("navpath");
    $(".navelem").removeClass("navelem");
    $(".tabs").removeClass("tabs");
    $(".tabs2").removeClass("tabs2");
    $(".tabs3").removeClass("tabs3");
    $(".tabs4").removeClass("tabs4");
    $(".header").removeClass("header");
    $(".headertitle").removeClass("headertitle");
    $(".textblock").removeClass("textblock");
    $(".even").removeClass("even");
    $(".directory").removeClass("directory");
    $(".tablist").removeClass("tablist");
    $(".memberdecls").removeClass("memberdecls");
    $(".memdoc").removeClass("memdoc");
    $(".memItemLeft").removeClass("memItemLeft");
    $(".memTemplItemLeft").removeClass("memTemplItemLeft")
    $(".memname").removeClass("memname");
    $(".memtemplate").removeClass("memtemplate");
    $(".ah").removeClass("ah").addClass("btn btn-default");

    $("body")
        .on('click.collapse-next.data-api', '[data-toggle=collapse-next]', function(){
            var $target = $(this).next();
            $target.data('bs.collapse') ? $target.collapse('toggle') : $target.collapse();
        })
        .fadeIn(150);
});
