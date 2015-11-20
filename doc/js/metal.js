$( document ).ready(function(){
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
        $(this).parent().parent().children().removeClass("active");
        $(this).parent().addClass("active");
    }).parent().removeClass("active");

    $("[id^='navrow'] > ul, #nav-path > ul")
        .addClass("nav nav-pills nav-justified")
        .find("a.el").removeClass("el");

    $("div.toc")
        .removeClass("toc")
        .addClass("panel pull-right")
        .attr("id", "toc");

    $("div#toc > ul").addClass("panel-body");
    $("div#toc h3")
        .addClass("panel-title").wrap("<div class='panel-heading'>");

    $("div.header")
        .each(function(){
            $("> div.headertitle > div.title", this)
                .wrapInner("<h1>")
                .contents()
                .prependTo($("+ div.contents", this));
        })
        .remove();

    $("h1").addClass("page-header");

    $("div.qindex + table td > a[href^='namespace']")
        .each(function(){
            var p = $(this).parent();
            $(this).remove();
            p.html(p.html().split("()").join(''));
        });

    $("div.memitem > div.memproto")
        .removeClass("memproto")
        .addClass("panel-heading")
        .each(function(){
            $("<div class='panel-title'>")
                .append($(".memtemplate", this).append("<br>").contents())
                .append($(".memname td", this).contents())
                .prependTo(this);

            $(".memtemplate", this).remove();
            $(".memname", this).remove();

        });

    $("div.memitem > div.memdoc").addClass("panel-body");
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

    $("a.el").removeClass("el").wrap("<strong>");

    $("table.memberdecls").addClass("table table-striped");

    $("table.directory").addClass("table table-striped");
    $("table.doxtable").addClass("table table-bordered");
    $("table.params").addClass("table");

    $("dl.section.see").replaceWith(function(){
        return $(this).find("dd").contents();
    });

    $("hr").remove();
    $(".levels").remove();
    $(".summary").remove();
    $(".desc").remove();
    $(".qindex").remove();
    $(".arrow").remove();
    $(".ttc").remove();
    $(".groupheader").remove();
    $(".ingroups").remove();
    $(".heading").remove();
    $(".memSeparator").remove();
    $("[class^='separator\\:']").remove();

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
    $(".memitem").removeClass("memitem");
    $(".memItemLeft").removeClass("memItemLeft");
    $(".memTemplItemLeft").removeClass("memTemplItemLeft")
    $(".memname").removeClass("memname");
    $(".memtemplate").removeClass("memtemplate");
    $(".ah").removeClass("ah").addClass("btn btn-default");
});
