$( document ).ready(function() {

    var menuOffsetY = $('#menu').offset().top;
    document.onscroll = function() {
        if ($(window).scrollTop() >= menuOffsetY) {
            $('#menu').addClass('navbar-fixed-top');
            $('.content').addClass('menu-padding');
            $('.hidden')
                .addClass('blur')
                .height($('#menu').height())
                .removeClass('hidden');
        } else {
            $('#menu').removeClass('navbar-fixed-top');
            $('.blur').addClass('hidden').removeClass('blur');
            $('.content').removeClass('menu-padding');
        }
    }

    $("div.title, h1").addClass("h1 page-header");

    $('li > a[href="index.html"] > span').before("<i class='octicon octicon-book'></i> ");
    $('li > a[href="files.html"] > span').before("<i class='octicon octicon-file-code'></i> ");
    $('li > a[href="modules.html"] > span').before("<i class='octicon octicon-code'></i> ");
    $('li > a[href="classes.html"] > span').before("<i class='octicon octicon-list-unordered'></i> ");
/*
    $('li > a[href="namespaces.html"] > span').before("<i class='fa fa-bars'></i> ");
    $('li > a[href="annotated.html"] > span').before("<i class='fa fa-list-ul'></i> ");
    $('li > a[href="inherits.html"] > span').before("<i class='fa fa-sitemap'></i> ");
    $('li > a[href="functions.html"] > span').before("<i class='fa fa-list'></i> ");
    $('li > a[href="functions_func.html"] > span').before("<i class='fa fa-list'></i> ");
    $('li > a[href="functions_vars.html"] > span').before("<i class='fa fa-list'></i> ");
    $('li > a[href="functions_enum.html"] > span').before("<i class='fa fa-list'></i> ");
    $('li > a[href="functions_eval.html"] > span').before("<i class='fa fa-list'></i> ");
*/
    $('img[src="ftv2ns.png"]').replaceWith('<span class="label label-danger">N</span> ');
    $('img[src="ftv2cl.png"]').replaceWith('<span class="label label-danger">C</span> ');

    $("div.tabs").removeClass("tabs");
    $("div.tabs2").removeClass("tabs2");
    $("ul.tablist").removeClass("tablist").addClass("nav nav-pills nav-justified");
    $("ul.tablist").css("margin-top", "0.5em");
    $("ul.tablist").css("margin-bottom", "0.5em");
    $("li.current").addClass("active");
    $("iframe").attr("scrolling", "yes");

    $('#nav-path > ul').html('').append(
        $('.ingroups').contents('a').wrap('<li>').parent()
    );
    $('.ingroups').remove();
    $("#nav-path > ul").addClass("nav nav-pills nav-justified");

    $("table.params").addClass("table");
    $("div.levels").remove();

    $("table.directory").addClass("table table-striped");
    $("div.summary").remove();
    $("table.fieldtable").addClass("table");
    $(".memitem").addClass("panel panel-default");
    $(".memSeparator").remove();
    $(".memproto").addClass("panel-heading");
    $(".memdoc").addClass("panel-body");
    $("span.mlabel").addClass("label label-info");
    $('td.memname, td.memTemplItemRight').contents().filter(function() {
        return this.nodeType == 3
    }).each(function(){
        this.textContent =
            this.textContent
                .replace('= typedef', '=')
                .replace(/= _.+[>]$/, '= /*unspecified*/');
    });

    $("table.memberdecls").addClass("table");
    $("table.memberdecls > tbody > tr.separator\\:").remove();
    $("[class^=memitem]").addClass("active");

    $("div.ah").addClass("btn btn-default");
    $("span.mlabels").addClass("pull-right");
    $("table.mlabels").css("width", "100%")
    $("td.mlabels-right").addClass("pull-right");

    $("div.ttc").addClass("panel panel-primary");
    $("div.ttname").addClass("panel-heading");
    $("div.ttname a").css("color", 'white');
    $("div.ttdef,div.ttdoc,div.ttdeci").addClass("panel-body");

    $('#MSearchBox').parent().remove();

    $('table.doxtable').addClass('table table-bordered');

    $('h2.groupheader').remove();

    $('table.memberdecls').find('.memItemRight').each(function(){
        $(this).contents().appendTo($(this).siblings('.memItemLeft'));
        $(this).siblings('.memItemLeft').attr('align', 'left');
    });

    function getOriginalWidthOfImg(img_element){
        var t = new Image();
        t.src = (img_element.getAttribute ? img_element.getAttribute("src") : false) || img_element.src;
        return t.width;
    }

    $('div.dyncontent').find('img').each(function(){
        if(getOriginalWidthOfImg($(this)[0]) > $('#content>div.container').width())
            $(this).css('width', '100%');
    });

    $(".memitem").removeClass('memitem');
    $(".memproto").removeClass('memproto');
    $(".memdoc").removeClass('memdoc');
    $("span.mlabel").removeClass('mlabel');
    $("table.memberdecls").removeClass('memberdecls');
    $("[class^=memitem]").removeClass('memitem');
    $("span.mlabels").removeClass('mlabels');
    $("table.mlabels").removeClass('mlabels');
    $("td.mlabels-right").removeClass('mlabels-right');
    $(".navpath").removeClass('navpath');
    $("li.navelem").removeClass('navelem');
    $("a.el").removeClass('el');
    $("div.ah").removeClass('ah');
    $("div.header").removeClass("header");

    $('.mdescLeft').each(function(){
        if($(this).html()=="&nbsp;") {
            $(this).siblings('.mdescRight').attr('colspan', 2);
            $(this).remove();
        }
    });

    $('td.memItemLeft').each(function(){
        if($(this).siblings('.memItemRight').html()=="") {
            $(this).attr('colspan', 2);
            $(this).siblings('.memItemRight').remove();
        }
        if($(this).text().match(/^directory/)) {
            $(this).html($(this).html().split("directory").join(""));
            $(this).prepend('<span class="octicon octicon-file-directory">');
        }
        if($(this).text().match(/^file/)) {
            $(this).html($(this).html().split("file").join(""));
            $(this).prepend('<span class="octicon octicon-file-code">');
        }
    });

    $('td.memItemLeft > span.octicon-file-code + b + a:contains([code])')
        .each(function(){
            $(this).html($(this).prev().text());
            $(this).prev().remove();
            $(this).prepend($(this).prev()).wrapInner('<strong>');
        });

    $('a[href*="_source.html"] > span.icondoc')
        .removeClass('icondoc')
        .addClass('octicon octicon-file-code')
        .each(function(){
            $(this).parent().append($(this).parent().next());
        });

    $('td.entry > span.iconfopen')
        .removeClass('iconfopen')
        .addClass('octicon octicon-file-directory')
        .removeAttr('onclick');

    $('span.octicon-file-directory + a').each(function(){
        $(this).prepend($(this).prev());
        $(this).wrapInner('<strong>');
    });

    $('td.entry > span.arrow').remove();

    $('td.desc').remove();

    $('div.qindex + table td > a[href^="namespace"]').each(function(){
        var p = $(this).parent();
        $(this).remove();
        p.html(p.html().split("()").join(""));
    })
    $('div.qindex').remove();
});
