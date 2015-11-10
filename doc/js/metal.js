$( document ).ready(function() {

    var menuOffsetY = $('#menu').offset().top;
    if(menuOffsetY > 0){
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
    }

    $('hr').remove();
    $('h2.groupheader').remove();
    $("div.levels").remove();
    $("div.summary").remove();
    $('td.desc').remove();
    $('td.entry > span.arrow').remove();
    $(".memSeparator").remove();
    $(".heading").remove();
    $("table.memberdecls > tbody > tr.separator\\:").remove();

    $(".navpath").removeClass('navpath');
    $("li.navelem").removeClass('navelem');
    $("a.el").removeClass('el');
    $("div.header").removeClass("header");
    $("div.tabs").removeClass("tabs");
    $("div.tabs2").removeClass("tabs2");
    $("div.directory").removeClass("directory");
    $("table.directory")
        .removeClass("directory")
        .addClass("table table-striped");
    $("ul.tablist")
        .removeClass("tablist")
        .addClass("nav nav-pills nav-justified");
    $("div.ah").removeClass('ah').addClass("btn btn-default");
    $("span.mlabels").removeClass('mlabels').addClass("pull-right");
    $("table.mlabels").removeClass('mlabels').css("width", "100%")
    $("td.mlabels-right").removeClass('mlabels-right').addClass("pull-right");
    $("table.fieldtable").removeClass("fieldtable").addClass("table");
    $("[class^=memitem]").addClass("active");
    $(".memitem").removeClass('memitem').addClass("panel panel-default");
    $(".memproto").removeClass('memproto').addClass("panel-heading");
    $(".memdoc").removeClass('memdoc').addClass("panel-body");
    $("span.mlabel").removeClass('mlabel').addClass("label label-info");
    $("div.title, h1").addClass("h1 page-header");
    $("li.current").addClass("active");
    $("div.ttc").addClass("panel panel-primary");
    $("div.ttname").addClass("panel-heading");
    $("div.ttdef,div.ttdoc,div.ttdeci").addClass("panel-body");
    $("table.params").addClass("table");
    $('table.doxtable').addClass('table table-bordered');

    $('li > a[href="index.html"] > span')
        .before("<i class='octicon octicon-book'></i> ");
    $('li > a[href="files.html"] > span')
        .before("<i class='octicon octicon-file-code'></i> ");
    $('li > a[href="modules.html"] > span')
        .before("<i class='octicon octicon-code'></i> ");
    $('li > a[href="classes.html"] > span')
        .before("<i class='octicon octicon-list-unordered'></i> ");

    $('img[src="ftv2ns.png"]')
        .replaceWith('<span class="label label-danger">N</span> ');
    $('img[src="ftv2cl.png"]')
        .replaceWith('<span class="label label-danger">C</span> ');

    $('div.qindex + table td > a[href^="namespace"]').each(function(){
        var p = $(this).parent();
        $(this).remove();
        p.html(p.html().split("()").join(""));
    })
    $('div.qindex').remove();

    $('dl.section.see').replaceWith(function(){
        return $(this).find('dd').contents();
    });

    $('#nav-path > ul')
        .addClass("nav nav-pills nav-justified")
        .html('').append(
            $('.ingroups').contents('a').wrap('<li>').parent()
        );
    $('.ingroups').remove();

    $('td.memname, td.memTemplItemRight').contents().filter(function() {
        return this.nodeType == 3
    }).each(function(){
        this.textContent =
            this.textContent
                .replace('= typedef', '=')
                .replace(/= (typename )?detail::.+$/, '= /*unspecified*/');
    });

    $("table.memberdecls")
        .removeClass('memberdecls')
        .addClass("table")
        .find('.memItemRight').each(function(){
            $(this).contents().appendTo($(this).siblings('.memItemLeft'));
            $(this).siblings('.memItemLeft').attr('align', 'left');
        });

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
});
