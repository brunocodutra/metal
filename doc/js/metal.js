// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

$(function(){
    var page = window.location.pathname.split("/").pop().split("#")[0];

    $("li > a[href='index.html'] > span")
        .before("<i class='octicon octicon-book'></i>");
    $("li > a[href='modules.html'] > span")
        .before("<i class='octicon octicon-code'></i>");
    $("li > a[href='namespacemembers.html'] > span")
        .before("<i class='octicon octicon-list-unordered'></i>");

    $(".current").removeClass("current").addClass("active");

    $("#navrow1 > ul > li").appendTo("#menu");

    $("#sections").on("click", function(){
        $("> .active > .name", this).text($("#menu > .active", this).text());
    }).click();

    if(/namespacemembers(_type)?\.html$/.test(page)){
        $("[id='navrow4']")
            .removeAttr("id")
            .addClass("hidden-xs")
            .find("> ul")
            .addClass("nav nav-pills nav-justified")
            .find("> li")
            .removeClass("active")
            .find("> a")
            .click(function(){
                $(this)
                    .parent().addClass("active")
                    .siblings().removeClass("active");
            });

        var $entries = $("h3").addClass("index-entry");

        $entries
            .find("+ ul")
            .addClass("list-inline")
            .find("> li")
            .each(function(){
                var text = $(this).text().match(/^([_a-zA-Z0-9]+)/g);
                $(this).html($("> a", this).html(text));
            });

        $entries.contents().each(function(){
            if(this.nodeType == 3)
                this.data = this.data.replace(/- (.+) -/g, "$1");
        })
    }

    $(".levels, .arrow, .heading, .memSeparator, \
        [id^='navrow'], [id^='nav-path'], [class^='separator\\:']").remove();

    $("div.header")
        .each(function(){
            $("> div.headertitle > div.title", this)
                .wrapInner("<h1>")
                .contents()
                .prependTo($("+ div.contents", this));
        })
        .remove();

    $("h1").addClass("page-header");
    $("h1.page-header > .ingroups")
        .removeClass("ingroups")
        .addClass("sub-page-header")
        .each(function(){
            $(this).parent().after(this);
        });

    $("div.toc").addClass("panel pull-right");
    $("div.toc > ul").addClass("panel-body");
    $("div.toc h3")
        .addClass("panel-title text-center")
        .wrap("<div class='panel-heading'>");

    $("div.contents").addClass("col-xs-12");

    var $memitem = $("div.memitem").addClass("panel panel-default");

    $("> div.memproto", $memitem)
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

    $("> div.memdoc", $memitem)
        .addClass("panel-body")
        .wrap("<div class='panel-collapse collapse'>")
        .find("> p:first-child > code:contains('#include')")
        .each(function(){
            var baseURL =
                "http://github.com/brunocodutra/metal/blob/master/include/";

            $(this).html(
                $(this).text().replace(
                    /^#include <([^>]+)>$/g,
                    "#include <<a href='" + baseURL + "$1'>$1</a>>"
                )
            );
        });

    $("table.memberdecls")
        .addClass("table table-striped")
        .find("td.memItemLeft, td.memTemplItemLeft")
        .each(function(){
            $("+ td", this).contents().appendTo(this);
            $("+ td", this);
        })
        .removeAttr("valign")
        .removeAttr("align");

    $("table.directory").addClass("table table-striped");
    $("table.doxtable")
        .addClass("table table-bordered")
        .wrap("<div class='table-responsive'>")
        .find("p.starttd, p.endtd")
        .replaceWith(function(){
            return $(this).contents();
        });

    $("dl.section.see").replaceWith(function(){
        return $(this).find("dd").contents();
    });

    $("div.fragment").replaceWith(function(){
        return $(this).wrapInner("<pre class='fragment'>").contents();
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

    $("a[href^='" + page + "#'], a[href^='#']").click(function(){
        var href = "#" + $.attr(this, "href").split("#").pop();
        if(href.length > 1){
            $("html, body").animate({
                scrollTop: $(href).offset().top
            }, 300, function(){
                window.location.hash = href;
            });

            return false;
        }

        return true;
    });

    $("body")
        .on(
            'click.collapse-next.data-api',
            '[data-toggle=collapse-next]',
            function(){
            var $target = $(this).next();
            $target.data('bs.collapse') ?
                $target.collapse('toggle') : $target.collapse();
        })
        .fadeIn(150);
});
