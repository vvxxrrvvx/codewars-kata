using System;
using System.Collections.Generic;
using System.Linq;

public class Pagination<T>
{
    private readonly IEnumerable<T> _source;
    private int _currentPage;
    private int _itemsPerPage;

    public Pagination(IEnumerable<T> source)
    {
        _source = source;
        _currentPage = 1;
        _itemsPerPage = 10;
    }

    public IEnumerable<T> Items => GetItemsForCurrentPage();
    public int CurrentPage
    {
        get => _currentPage;
        set => _currentPage = Math.Max(1, value);
    }

    public int ItemsPerPage
    {
        get => _itemsPerPage;
        set => _itemsPerPage = value > 0 ? value : 10;
    }

    public int Total => _source.Count();
    public int TotalPages => (int)Math.Ceiling((double)Total / ItemsPerPage);

    private IEnumerable<T> GetItemsForCurrentPage()
    {
        if (CurrentPage > TotalPages)
            return Enumerable.Empty<T>();

        return _source.Skip((CurrentPage - 1) * ItemsPerPage).Take(ItemsPerPage);
    }
}