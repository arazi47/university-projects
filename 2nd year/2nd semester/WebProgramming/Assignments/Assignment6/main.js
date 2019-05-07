$('document').ready(function(){
	$("body").attr('style',  'background-color:pink');

	$('ul').css({
		'list-style' : 'none',
		'padding' : '0px',
		'margin' : '0px'
	});
	
	$('ul li').css({
		'display' : 'block',
		'position' : 'relative',
		'float' : 'left',
		'border' : '1px solid #000'
	});
	
	$('li ul').css({
		'display' : 'none'
	});
	
	$('ul li a').css({
		'display' : 'block',
		'background' : '#000',
		'padding' : '5px 10px 5px 10px',
		'text-decoration' : 'none',
		'white-space' : 'nowrap',
		'color' : '#fff'
	});
	
	/*
	$('ul li a:hover').css({
		'background' : '#f00'
	});
	
	$('li:hover ul').css({
		'display' : 'block',
		'position' : 'absolute'
	});
	
	$('li:hover li').css({
		'float' : 'none'
	});
	
	$('li:hover a').css({
		'background' : '#f00'
	});
	
	$('li:hover li a:hover').css({
		'background' : '#000'
	});
	*/
	
	$('#drop-nav li ul li').css({
		'border-top' : '0px'
	});

	/*
	$('ul li a').hover(
		function() {
			$(this).css('background', '#f00');
			$(this).css('transition', 'all 0.15s');
		},
		function() {
			$(this).css('background', '#000');
			$(this).css('transition', 'all 0s');
		}
	);
	*/

	/*
	$('li').hover(
		function() {
			$(this).find('ul').css('display', 'block');
			$(this).find('ul').css('position', 'absolute');
			$(this).find('ul').css('transition', 'all 1s');
		},
		function() {
			$(this).find('ul').css('display', 'none');
			$(this).find('ul').css('position', 'relative');
			$(this).find('ul').css('transition', 'all 0s');
		}
	);
	*/

	$('li').click(function() {
		$(this).find('ul').css('display', 'block');
		$(this).find('ul').css('position', 'absolute');
		$(this).closest('li').find('>ul').css({'opacity':0,'margin-top':15}).show().animate({'margin-top':0,'opacity':1},300);
	},function() {
		$(this).find('ul').css('display', 'block');
		$(this).find('ul').css('position', 'absolute');
		$(this).closest('li').find('>ul').css({'opacity':0,'margin-top':15}).show().animate({'margin-top':0,'opacity':1},300);
	});

	$('li').mouseleave(function() {
		$(this).find('ul').css('display', 'none');
		//$(this).find('ul').css('position', 'absolute');
		$(this).closest('li').find('>ul').css({'opacity':0,'margin-top':15}).show().animate({'margin-top':0,'opacity':1},0);
		$(this).closest('li').find('>ul').fadeOut(200,function(){
			 $(this).hide();   
		});
	});
});
